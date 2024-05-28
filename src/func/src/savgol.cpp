#include "savgol.h"

#include <Eigen/Dense>
#include <Eigen/LU>
#include <Eigen/Core>
#include <Eigen/QR>
#include <iostream>

using namespace Eigen;


/*Compute the polynomial basis vectors s_0, s_1, s_2 ... s_n using the vandermonde matrix.*/
MatrixXi savgol::vander(const int F)
{
  auto v = VectorXi::LinSpaced(F,(-(F-1)/2),((F-1)/2)).transpose().eval();

  MatrixXi A(F, F+1);   

  for(auto i = 0; i < F; ++i)
  {
    for(auto j=0; j < F+1; ++j)
    {
      A(i,j) = pow(v(i), (j) ); 
    }
  }

//A = A.block(0, 1, F, F );   //retrieve the right F X F matrix block, excluding the first column block to find the vandermonde matrix.

  return A;
}

/*brief Compute the S-Golay Matrix of differentiators*/
MatrixXf savgol::sgdiff(int k, int F, double Fd)
{
    //We set the weighting matrix to an identity matrix if no weighting matrix is supplied
    auto W = MatrixXf::Identity(Fd, Fd);      

    //Compute Projection Matrix B
    auto s = vander(F);   

    //Retrieve the rank deficient matrix from the projection matrix
    auto S = s.block(0, 0, s.rows(), (k+1) ) ; 

    //Compute sqrt(W)*S
    auto Sd = S.cast<float> ();    //cast S to float
    auto inter = W * Sd;           //W is assumed to be identity. Change this if you have reasons to.

    //Compute the QR Decomposition
    HouseholderQR<MatrixXf> qr(inter);
    qr.compute(inter);

    //retrieve rank of matrix  
    FullPivLU<MatrixXf>lu_decomp(inter);      
    auto Rank = lu_decomp.rank();

    //For rank deficient matrices. The S matrix block will always be rank deficient.        
    // MatrixXf Q = qr.householderQ();  //unsused
    MatrixXf R = qr.matrixQR().topLeftCorner(Rank, Rank).triangularView<Upper>();

    //Compute Matrix of Differentiators
    auto Rinv = R.inverse();

    MatrixXf RinvT = Rinv.transpose();

    MatrixXf G = Sd * Rinv * RinvT;    /*G = S(S'S)^(-1)   -- eqn 8.3.90 (matrix of differentiation filters)*/

    MatrixXf SdT = Sd.transpose().eval();

    MatrixXf B = G * SdT * W;   //SG-Smoothing filters of length F and polynomial order k

    return B;
    }

// input x is a  vector
RowVectorXf savgol::savgolfilt(VectorXf const & x, int k, int F){  

    //Find leading singleton dimensions
    auto Fd = static_cast<double>(F);  //sets the frame size for the savgol differentiation coefficients. This must be odd
    auto B = sgdiff(k, F, Fd); 
            
    /*Transient On*/
    auto id_size = (F-1)/2 ;
    auto Bbutt = B.bottomLeftCorner((F-1)/2, B.cols()); 
    auto n = Bbutt.rows(); 
    //flip Bbutt from top all the way down 
    MatrixXf Bbuttflipped(n, Bbutt.cols());
    for(auto j = n - 1; j >= 0;)
    { 
        for(auto i = 0; i < n ; ++i)
        {        
            Bbuttflipped.row(i) = Bbutt.row(j);
            j--;
        }
    }

    //flip w_on and w_off up and down as above
    VectorXf w_on(F,1),w_off(F,1);
    for(auto i=0;i<F;i++){
        w_on(i)=x(F-i-1);
        w_off(i)=x(x.size()-i-1);
    }

    //Now compute the transient on
    VectorXf y_on = Bbuttflipped * w_on; 
    
    /*Compute the steady state output*/
    size_t idzeroth = floor(B.cols()/2);
    auto Bzeroth = B.col(idzeroth);
    auto Bzerothf = Bzeroth.cast<float>();

    MatrixXf w_s(F, x.size()-(F-1));  
    auto c=F;
    for(auto j=0; j<x.size()-(F-1);j++)
    {
        c=F-1;
        for (auto i = j; i < j+F; i++)
        {
            w_s(c,j)=x(i);
            c--;    
        }
    }
    
    auto y_ss = Bzerothf.transpose() * w_s;  //This is the steady-state smoothed value

    /*Compute the transient off for non-sequential data*/
    auto Boff = B.topLeftCorner((F-1)/2, B.cols());
    
    //flip Boff along the horizontal axis
    auto p = Boff.rows();                       
    MatrixXf Boff_flipped(p, Boff.cols());

    for(auto j = p - 1; j >= 0;)
    { 
        for(auto i = 0; i < p ; ++i)
        {        
            Boff_flipped.row(i) = Boff.row(j);
            j--;
        }
    }

    auto y_off = Boff_flipped * w_off;   //This is the transient off

    /*Make Y into the shape of X and retuen the smoothed values!*/
    RowVectorXf y(x.size());
    y << y_on.transpose(), y_ss, y_off.transpose();
    std::cout<<"\n y"<<y<<std::endl;
    return y;
}


