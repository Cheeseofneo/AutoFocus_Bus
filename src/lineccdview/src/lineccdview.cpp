#include "lineccdview/headers/lineccdview.h"
#include "lineccdview/headers/qcustomplot.h"
#include "ui_lineccdview.h"
#include <QtWidgets/QMessageBox>
#include <QTSerialPort/QSerialPortInfo>
#include <QtCore/QDebug>

MyThreadSerial * gl_serial = NULL;

//#define USE_ILX554
//#define USE_ILX511

#define USE_S11639_11638
#define data_head 5
#define data_crc 2

#ifdef USE_ILX511

#define Pixels_ALL 2086  //32 Dummy pixels+ 2048 Effective pixels + 6 Dummy pixels
#define Pixels_Dummy 32
#define Pixels_Effective 2048
#define SensorType "ILX511_511"

#endif

#ifdef USE_ILX554

#define Pixels_ALL 2086  //32 Dummy pixels+18black + 2048 Effective pixels + 6 Dummy pixels
#define Pixels_Dummy 32
#define Pixels_Effective 2048
#define SensorType "ILX511_554"

#endif

#ifdef USE_TCD1304

#define Pixels_ALL 3694  //32 Dummy pixels + 3648 Effective pixels + 14 Dummy pixels
#define Pixels_Dummy 32
#define Pixels_Effective 3648
#define SensorType "TCD1304"


#endif

#ifdef USE_S11639_11638

#define Pixels_ALL 2048
#define Pixels_Dummy 0
#define Pixels_Effective 2048
#define SensorType "S11639_11638"

#endif

unsigned char cmd[] = {0x81,0x00,0x00,0x00,0xff};
lineccdview *ptrMainWindow;

void MyThreadSerial::ThreadopenMycom(QString port)
{
    m_Com = new QSerialPort(this);
    m_Com->setPortName(port);
    m_Com->open(QIODevice::ReadWrite); //设置为可读写模式
    if(!m_Com->isOpen())
    {
        QMessageBox::about(NULL, "About", port+" Failed to open!");
        return;
    }
    m_Com->setBaudRate(QSerialPort::Baud115200);//波特率是固定的吗？
    m_Com->setDataBits(QSerialPort::Data8);
    m_Com->setParity(QSerialPort::NoParity);
    m_Com->setStopBits(QSerialPort::OneStop);
    m_Com->setFlowControl(QSerialPort::NoFlowControl);
    m_Com->setReadBufferSize(Pixels_ALL *2 +data_head + data_crc);//buffer大小
    if(m_Com->open(QIODevice::ReadWrite))
    {
        m_Com->setDataTerminalReady(true); //设置为一直发送数据 因为没有流控制
    }
    m_Com->clear();//Discards all characters from the output or input buffer，Also terminate pending read or write operations

    connect(m_Com,&QSerialPort::readyRead,this,&MyThreadSerial::readData);

}

void MyThreadSerial::writeMyCom(QByteArray senddata)
{
    if(m_Com->isOpen())
    {
        m_Com->write(senddata);
    }
}
void MyThreadSerial::run() // 因为该线程可以执行读和写操作，而且不是循环执行，所以不在run中开启，而是分别构建两个开启函数
{

}


void MyThreadSerial::readData()
{
    QByteArray data;

    data = m_Com->readAll();

    if(!data.isEmpty()) //如果读到的数据不为空
    {
        emit ThreadMyCom(data);
    }

}

//**************************************************************************************

lineccdview::lineccdview(QWidget *parent):
    QWidget(parent),ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("YMLineCCDView:V0.01   Build: 20231102   Sensor: "+ QString(SensorType) );
    ptrMainWindow = this;
    this->showMaximized();

    m_averageTimes = 1;
    QList<QSerialPortInfo> serialPortInfoList = QSerialPortInfo::availablePorts(); //可用的端口号
    for(int i=0;i<serialPortInfoList.length();i++)
    {
        ui->comboBox->addItem(serialPortInfoList.at(i).portName());
    }

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));

    timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(timerUpDate2()));

    serial = new MyThreadSerial(this);
    m_DlgConfig = new Dialog_config(this);
    
    connect(serial,SIGNAL(ThreadMyCom(QByteArray)),this,SLOT(readMyCom(QByteArray)));
    //ThreadMyCom是信号，并无实际意义，只要serial线程发出该信号，就开始执行readMyCom，所以触发关键是看谁在emit

    gl_serial = serial;
    m_myEdit = new QTextEdit;

    m_myEdit = ui->textEdit;

    m_len = 0;
    m_frame = 0;
    m_speed = 0;
    m_writeFlash = false;
    m_smooth = 1;
    m_Xdata.clear();

    for(int i=0;i<Pixels_ALL;i++)
    {
        m_CCDData_Pixels.append(i);
        m_CCDData.append(i);
    }// spectrum的数据

    setupPlot();

    ui->pushButton_Cou->setToolTip(tr("Continuous display"));
    ui->pushButton_Send->setToolTip(tr("Single display"));
    ui->pushButton_Pause->setToolTip(tr("Pause display"));
    ui->lineEdit_Int->setToolTip(tr("Exposure time (20us-65s)"));
    ui->lineEdit_Avg->setToolTip(tr("Average times (1-255)"));
    ui->lineEdit_smooth->setToolTip(tr("Smoothing level (1-10)"));
    ui->lineEdit_Filterlevel->setToolTip(tr("Filter level (1-50)"));
    ui->lineEdit_interval->setToolTip(tr("trigger interval (0-65535ms)"));
    ui->pushButton_GetDark->setToolTip(tr("Get background"));
    ui->checkBox_removeDark->setToolTip(tr("Remove background"));
    ui->checkBox->setToolTip(tr("Zoom in coordinates"));
    ui->pushButton_Save->setToolTip(tr("Save data"));

    ui->textEdit->setToolTip(tr("Must be 2048 data, data valid values 0-65535, one row per data"));
    ui->lineEdit_Avg->setText("1");

    ui->lineEdit_Int->setEnabled(false);
    ui->pushButton_Cou->setEnabled(false);
    ui->pushButton_SetInt->setEnabled(false);
    ui->pushButton_Send->setEnabled(false);
    ui->progressBar->setEnabled(false);
    ui->pushButton_Save->setEnabled(false);
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
    ui->pushButton_Pause->setEnabled(false);
    ui->checkBox->setEnabled(false);

    ui->groupBox_7->setEnabled(false);
    ui->pushButton_SetAvg->setEnabled(false);
    ui->lineEdit_Avg->setEnabled(false);

    ui->comboBox_unit->setEnabled(false);
    ui->lineEdit_smooth->setEnabled(false);
    ui->pushButton_SetSmooth->setEnabled(false);
    ui->pushButton_filter->setEnabled(false);
    ui->pushButton_SetInterval->setEnabled(false);
    ui->pushButton_GetDark->setEnabled(false);
    ui->checkBox_removeDark->setEnabled(false);
    m_integrationTime = 0;

    on_textEdit_textChanged();
}

lineccdview::~lineccdview()
{
    delete ui;
}


void lineccdview::on_textEdit_textChanged()
{
    int rowCount = m_myEdit ->document()->lineCount(); //获取行数
    ui->label_ZFcounter->setText(QString::number(rowCount));
}

void lineccdview::setupPlot()  //plot spectrum
{
    ui->plot->xAxis->setLabel("Pixels");
    ui->plot->xAxis->setLabelFont(QFont("Helvetica",7));

    ui->plot->xAxis->setRange(0,Pixels_ALL);
    ui->plot->yAxis->setRange(0,65535);
    ui->plot->legend->setVisible(true);             //
    ui->plot->legend->setFont(QFont("Helvetica",8));
    ui->plot->setFont(QFont("Helvetica",6));
    ui->plot->xAxis->setTickLabelFont(QFont("Helvetica",7));
    ui->plot->yAxis->setTickLabelFont(QFont("Helvetica",7));

    ui->plot->xAxis->setUpperEnding(QCPLineEnding::esFlatArrow);
    ui->plot->yAxis->setUpperEnding(QCPLineEnding::esFlatArrow);


    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::red));
    ui->plot->graph(0)->setVisible(true);
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom); // zoom

    ui->plot->graph(0)->setName(("data"));

}

void lineccdview::timerUpDate2()
{
    static int cc = 0;
    cc++ ;
    if(cc == 1)
    {
        GetIntegrationTime();
    }
    else if(cc ==2)
    {
        GetIntegrationUnit();
    }
    else if(cc ==3)
    {
        GetAvgTimes();
    }
    else if(cc ==4)
    {
        GetGain();
    }
    else if(cc ==5)
    {
        GetOffset();
    }
    else if(cc ==6)
    {
        on_pushButton_Bandrate_read_clicked();
    }
    else if(cc ==7)
    {
        GetSmooth();

    }
    else if(cc ==8)
    {
        GetInterval();
    }

    else if(cc ==9)
    {
        readCoff_1();
    }
    else if(cc ==10)
    {
        readCoff_2();
    }

    else if(cc ==11)
    {
        readCoff_3();
        cc = 0;
        timer2->stop();
    }
}


void lineccdview::timerUpDate3()
{
    on_pushButton_Send_clicked();
}

void lineccdview::timerUpDate()
{

    ui->label_f->setText(tr("Display rate：")+QString::number(m_frame)+" fps   ");
    ui->label_f2->setText(tr("Read rate：")+QString::number(m_speed)+" fps  ");
    m_len = 0;
    m_frame = 0;
    m_frameDelay = m_speed/30;
    if(m_frameDelay<1) m_frameDelay = 1;
    m_speed = 0;

    QList<QSerialPortInfo> serialPortInfoList = QSerialPortInfo::availablePorts();
    for(int i=0;i<serialPortInfoList.length();i++)
    {
        if(ui->comboBox->currentText()!=serialPortInfoList.at(i).portName())
        {
            ui->comboBox->addItem(serialPortInfoList.at(i).portName());
        }
    }

    if((  m_button_state == single )||( m_button_state ==countinuous ))
    {
        if(m_integrationTime >=1000)
        {
            if(m_progressValue<=100)
            {
                uint8_t avg = ui->lineEdit_Avg->text().toInt();
                m_progressValue += 100/((m_integrationTime*avg)/1000);
            }
            //            else
            //              {
            //                m_progressValue = 0;
            //              }
            ui->progressBar->setValue(m_progressValue);
        }
    }

    if(m_writeFlash)
    {
        if(m_flashWtrieTime>0)
        {
            ui->label_flash_write->setText("Flash writeing: "+QString::number(m_flashWtrieTime--)+" s");
            ui->groupBox_7->setEnabled(false);
        }
        else
        {
            ui->label_flash_write->setText("Flash write complete!");
            m_writeFlash = false;
            ui->groupBox_7->setEnabled(true);
        }
    }
}

/*
    对读入的数据进行处理
*/
void lineccdview::readMyCom(QByteArray ccd_ba)
{
    static double lost=0;
    m_len = ccd_ba.length();
    static QByteArray ccd_data;

    if(ccd_data.length()<Pixels_ALL *2 +data_head + data_crc)
    {
        ccd_data+=ccd_ba; //此处的＋与append的作用相同
    }
    if(ccd_data.length()>=Pixels_ALL *2 +data_head + data_crc)
    {
        if(m_button_state == single)
            m_button_state = stop;
        if((ccd_data[0].operator==(0x81))&&(ccd_data[1].operator==(0x01)))
        {
            m_speed++;
            m_CCDData.clear();
            quint16 crc = 0;
            for(int i=5;i<Pixels_ALL*2+5;) // 将data从8位整合为16位
            {
                quint8 tempH = ccd_data[i];
                i++;
                crc += tempH;
                quint8 tempL = ccd_data[i];
                i++;
                crc += tempL;
                quint16 temp = tempH<<8|tempL;
                m_CCDData.push_back(temp);
            }
            quint8 crc_h = ccd_data.at(5+Pixels_ALL*2);
            quint8 crc_l = ccd_data.at(5+Pixels_ALL*2+1);
            quint16 crc_image = crc_h<<8|crc_l;
            if(m_speed%m_frameDelay==0)  //显示帧率控制
            {
                if(crc_image==crc)
                {
                    double input[Pixels_ALL];
                    // 第一和二个for循环是remove背景噪声，为啥还要用input浪费空间？
                    for(int i=0;i<m_CCDData.length();i++)
                    {
                        if(ui->checkBox_removeDark->isChecked())
                            input[i]=m_CCDData.at(i)-m_BaseData.at(i);
                        else
                            input[i]=m_CCDData.at(i);

                    }
                    m_CCDData.clear();
                    for(int i=0;i<Pixels_ALL;i++)
                    {
                        m_CCDData.append(input[i]);
                    }

                    ////////
                    if(m_Xdata.length()>0)
                        ui->plot->graph(0)->setData(m_Xdata, m_CCDData);
                    else
                        ui->plot->graph(0)->setData(m_CCDData_Pixels, m_CCDData);

                    if(ui->checkBox->isChecked())
                        ui->plot->rescaleAxes();
                    else
                        ui->plot->yAxis->setRange(0,65535);
                    ui->plot->replot();
                    m_frame++;
                    emit ThreadCCDdata(m_CCDData);
                }
                
                else
                {
                    lost++;
                    ui->label_lost->setText(QString::number(lost)); //丢失帧
                }
                ui->progressBar->setValue(100);
                m_progressValue = 0;
            }
        }
        // 读取x坐标值的返回码
        if((ccd_data[0].operator==(0x81))&&(ccd_data[1].operator==(0x14)))
        {
            quint16 crc = 0;
            for(int i=5;i<Pixels_ALL*2+5;)
            {
                quint8 tempH = ccd_data[i];
                i++;
                crc += tempH;
                quint8 tempL = ccd_data[i];
                i++;
                crc += tempL;
                quint16 temp = tempH<<8|tempL;
                // double x = temp;
                // m_Xdata.push_back(x);
                m_Xdata.push_back(temp);
            }
            quint8 crc_h = ccd_data.at(5+Pixels_ALL*2);
            quint8 crc_l = ccd_data.at(5+Pixels_ALL*2+1);
            quint16 crc_image = crc_h<<8|crc_l;
            if(crc_image==crc)
            {
                QString str;
                ui->plot->xAxis->setRange(m_Xdata.first(),m_Xdata.last());
                ui->plot->replot();
                for (int i=0;i<m_Xdata.length();i++) {
                    str += QString::number(m_Xdata.at(i),'f',1)+"\r\n";
                }
                ui->textEdit->setPlainText(str);
            }
        }
        ccd_data.clear();
    }
    else // hdinfo
    {
        if(ccd_data.contains("HdInfo"))
        {
            QString Info_str = ccd_data;
            QStringList InfoList2;
            QStringList InfoList = Info_str.split(':');
            if(InfoList.length()>0)
                InfoList2 = InfoList[1].split(',');


            ui->label_HardwareInfo->setText("Hardware Info.:"+InfoList[1]);
            ui->label_ComSta->setPixmap(QPixmap(":/res/visible.png"));

            ccd_data.clear();

        }
        if(ccd_data[0].operator==( 0x81))
        {
            if(ccd_data[1].operator==( 0x02))  //积分时间
            {
                quint8 h = ccd_data[2];
                quint8 l = ccd_data[3];
                quint16 int_time = h<<8|l;
                m_integrationTime = int_time;
                ui->lineEdit_Int->setText(QString::number(m_integrationTime));
                ccd_data.clear();
            }
            else if(ccd_data[1].operator==( 0x0b))  //interval
            {
                quint8 h = ccd_data[2];
                quint8 l = ccd_data[3];
                quint16 interval = h<<8|l;
                ui->lineEdit_interval->setText(QString::number(interval));
                ccd_data.clear();
            }
            else if(ccd_data[1].operator==( 0x12))  //积分时间单位
            {
                if(ccd_data[2].operator==(0x00))
                    ui->comboBox_unit->setCurrentText("ms");
                else if(ccd_data[2].operator==(0x01))
                    ui->comboBox_unit->setCurrentText("us");
                ccd_data.clear();
            }
            else if(ccd_data[1].operator==( 0x0e))  //平均次数
            {
                quint8 avgtimes = ccd_data[2];
                ui->lineEdit_Avg->setText(QString::number(avgtimes));
                ccd_data.clear();
            }
            else if(ccd_data[1].operator==( 0x16))  //波特率
            {
                quint8 bandrate = ccd_data[2];
                if(bandrate==1)m_DlgConfig->SetRadio_1(1);
                else if(bandrate==2) m_DlgConfig->SetRadio_2(1);
                else if(bandrate==3) m_DlgConfig->SetRadio_3(1);
                ccd_data.clear();
            }
            else if(ccd_data[1].operator==( 0x23))  //增益
            {
                quint8 index = ccd_data[2];
                m_lineEdit_Gain =index;
                ccd_data.clear();
            }
            else if(ccd_data[1].operator==( 0x24))  //偏移
            {
                quint8 index = (quint8)ccd_data[2];
                if(ccd_data[3].operator==(0x01))
                    m_lineEdit_Offset = index;
                else
                    m_lineEdit_Offset = 0-index;
                ccd_data.clear();
            }
            else if(ccd_data[1].operator==( 0x25))  //
            {
                quint8 index = ccd_data[2];
                ui->lineEdit_smooth->setText(QString::number(index));
                ccd_data.clear();
            }
            else if(ccd_data[1].operator==( 0x29))  //coff
            {
                quint8 cmd = ccd_data[2];
                QString f[4];
                if(cmd == 0x01)  //m_coff_1
                {
                    for(int i=4;i<16+4;i++)
                        f[0] += ccd_data[i];
                    for(int i=16+4;i<4+16*2;i++)
                        f[1] += ccd_data[i];
                    for(int i=4+16*2;i<4+16*3;i++)
                        f[2] += ccd_data[i];
                    for(int i=4+16*3;i<4+16*4;i++)
                        f[3] += ccd_data[i];
                    m_coff_1.f[0] = f[0];
                    m_coff_1.f[1] = f[1];
                    m_coff_1.f[2] = f[2];
                    m_coff_1.f[3] = f[3];
                }

                else if(cmd == 0x02) //m_coff_2
                {
                    for(int i=4;i<16+4;i++)
                        f[0] += ccd_data[i];
                    for(int i=16+4;i<4+16*2;i++)
                        f[1] += ccd_data[i];
                    for(int i=4+16*2;i<4+16*3;i++)
                        f[2] += ccd_data[i];
                    for(int i=4+16*3;i<4+16*4;i++)
                        f[3] += ccd_data[i];
                    m_coff_2.f[0] = f[0];
                    m_coff_2.f[1] = f[1];
                    m_coff_2.f[2] = f[2];
                    m_coff_2.f[3] = f[3];
                }

                else if(cmd == 0x03) //m_coff_3
                {
                    for(int i=4;i<16+4;i++)
                        f[0] += ccd_data[i];
                    for(int i=16+4;i<4+16*2;i++)
                        f[1] += ccd_data[i];
                    for(int i=4+16*2;i<4+16*3;i++)
                        f[2] += ccd_data[i];
                    for(int i=4+16*3;i<4+16*4;i++)
                        f[3] += ccd_data[i];
                    m_coff_3.f[0] = f[0];
                    m_coff_3.f[1] = f[1];
                    m_coff_3.f[2] = f[2];
                    m_coff_3.f[3] = f[3];
                }

                if(!m_Dlg.isHidden())
                    m_Dlg.init();
                ccd_data.clear();
            }
        }
    }

}

void lineccdview::on_pushButton_Close_clicked()
{
    on_pushButton_Pause_clicked();
    serial->m_Com->close();
    timer->stop();
    ui->lineEdit_Int->setEnabled(false);
    ui->pushButton_Cou->setEnabled(false);
    ui->pushButton_SetInt->setEnabled(false);
    ui->pushButton_Send->setEnabled(false);
    ui->progressBar->setEnabled(false);
    ui->pushButton_Save->setEnabled(false);
    ui->pushButton_Pause->setEnabled(false);
    ui->checkBox->setEnabled(false);
    m_checkBox_HdTrigger = 0;
    m_DlgConfig->SetcheckBox_HdTrigger(m_checkBox_HdTrigger);
    ui->pushButton_Open->setEnabled(true);
    ui->pushButton_SetAvg->setEnabled(false);

    ui->lineEdit_Avg->setEnabled(false);
    m_groupBox = 0;
    m_groupBox_2 = 0;
    m_groupBox_5 = 0;
    m_DlgConfig->SetgroupBox(m_groupBox);
    m_DlgConfig->SetgroupBox2(m_groupBox_2);
    m_DlgConfig->SetgroupBox5(m_groupBox_5);
    ui->groupBox_7->setEnabled(false);

    ui->comboBox_unit->setEnabled(false);
    ui->lineEdit_smooth->setEnabled(false);
    ui->pushButton_SetSmooth->setEnabled(false);
    ui->pushButton_filter->setEnabled(false);
    ui->pushButton_GetDark->setEnabled(false);
}

void lineccdview::on_pushButton_Open_clicked()
{
    serial->ThreadopenMycom(ui->comboBox->currentText());
    if(serial->m_Com->isOpen())
    {
        ui->lineEdit_Int->setEnabled(true);
        ui->pushButton_Cou->setEnabled(true);
        ui->pushButton_SetInt->setEnabled(true);
        ui->pushButton_Send->setEnabled(true);
        ui->progressBar->setEnabled(true);
        ui->pushButton_Save->setEnabled(true);
        ui->pushButton_Pause->setEnabled(true);
        ui->checkBox->setEnabled(true);
        m_checkBox_HdTrigger = 1;
        m_DlgConfig->SetcheckBox_HdTrigger(m_checkBox_HdTrigger);
        ui->pushButton_Open->setEnabled(false);

        ui->pushButton_SetAvg->setEnabled(true);
        ui->lineEdit_Avg->setEnabled(true);
        m_groupBox = 1;
        ui->groupBox_7->setEnabled(true);
        m_groupBox_5 = 1;


        m_DlgConfig->SetgroupBox(m_groupBox);
        m_DlgConfig->SetgroupBox5(m_groupBox_5);
        ui->comboBox_unit->setEnabled(true);
        ui->lineEdit_smooth->setEnabled(true);
        ui->pushButton_SetSmooth->setEnabled(true);
        ui->pushButton_GetDark->setEnabled(true);
        ui->pushButton_SetInterval->setEnabled(true);
        ui->lineEdit_interval->setEnabled(true);
        ui->pushButton_filter->setEnabled(true);
        ui->lineEdit_Filterlevel->setEnabled(true);

        m_progressValue = 0;
        timer->start(1000);
        GetHardwareInfo();
        getPar();
    }
}

void lineccdview::getPar()
{
    timer2->start(100);
}


void lineccdview::on_pushButton_Send_clicked()
{
    QByteArray ba((char*)cmd, 5);
    ba[1] = 1;
    serial->writeMyCom(ba);
    ui->progressBar->setValue(0);

    m_progressValue = 0;
    m_button_state = single;
    if(m_checkBox_HdTrigger)
    {
       m_checkBox_HdTrigger = 0;
       m_DlgConfig->SetcheckBox_HdTrigger(m_checkBox_HdTrigger);
    }
}

void lineccdview::on_pushButton_Cou_clicked()
{
    QByteArray ba((char*)cmd, 5);
    ba[1] = 2;
    serial->writeMyCom(ba);
    m_button_state = countinuous;

    if(m_checkBox_HdTrigger)
    {
       m_checkBox_HdTrigger = 0;
        m_DlgConfig->SetcheckBox_HdTrigger(m_checkBox_HdTrigger);
    }
}

void lineccdview::on_pushButton_SetInt_clicked()
{


    if(ui->comboBox_unit->currentText()=="ms")
    {
        if(ui->lineEdit_Int->text().toShort()<1)
            ui->lineEdit_Int->setText("1");
        else if(ui->lineEdit_Int->text().toUShort()>60000)
            ui->lineEdit_Int->setText("60000");
    }
    else if(ui->comboBox_unit->currentText()=="us")
    {
        if(ui->lineEdit_Int->text().toShort()<20)
            ui->lineEdit_Int->setText("20");
        else if(ui->lineEdit_Int->text().toShort()>999)
            ui->lineEdit_Int->setText("999");
    }
    QByteArray ba((char*)cmd, 5);
    ba[1] = 3;
    m_integrationTime = ui->lineEdit_Int->text().toShort();
    ba[2] = m_integrationTime>>8;
    ba[3] = (char)m_integrationTime;
    serial->writeMyCom(ba);

    SetIntUnit(ui->comboBox_unit->currentText());
}


void lineccdview::on_pushButton_Save_clicked()
{
    //将选中物质保存为文本数据
    ui->pushButton_Save->setEnabled(false);
    QString selfilter;
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Data"),
                                                    "",
                                                    tr("*.txt;;*.csv"),&selfilter);
    if (!fileName.isNull())
    {
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Truncate))
        {
            QMessageBox::warning(this,"warning","can't open",QMessageBox::Yes);
        }
        QTextStream in(&file);
        if(selfilter==("*.txt"))
        {
            for(int i = 0;i<m_CCDData.length();i++)
            {
                in<<QString::number(m_CCDData_Pixels[i]) + " "+ QString::number(m_CCDData[i])<<"\n";
            }
        }
        else if(selfilter==("*.csv"))
        {
            for(int i = 0;i<m_CCDData.length();i++)
            {
                in<<QString::number(m_CCDData_Pixels[i]) + ','+ QString::number(m_CCDData[i])<<"\n";
            }
        }
        file.close();
    }
    else
    {
        //点的是取消
    }



    ui->pushButton_Save->setEnabled(true);


}

void lineccdview::on_pushButton_Pause_clicked()
{
    QByteArray ba((char*)cmd, 5);
    ba[1] = 6;
    serial->writeMyCom(ba);
    m_button_state = stop;
    if(m_checkBox_HdTrigger)
    {
       m_checkBox_HdTrigger = 0;
        m_DlgConfig->SetcheckBox_HdTrigger(m_checkBox_HdTrigger);
    }
}

void lineccdview::GetHardwareInfo()
{

    QByteArray ba((char*)cmd, 5);
    ba[1] = 9;
    serial->writeMyCom(ba);

}


void lineccdview::GetIntegrationTime()
{

    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x0a;
    serial->writeMyCom(ba);
}



void lineccdview::GetIntegrationUnit()
{

    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x12;
    serial->writeMyCom(ba);

}

void lineccdview::GetAvgTimes()
{

    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x0e;
    serial->writeMyCom(ba);

}


void lineccdview::GetGain()
{

    QByteArray ba((char*)cmd, 5);
    ba[1] =  0x23;
    ba[4] = ba[0]+ba[1]+ba[2]+ba[3];

    serial->writeMyCom(ba);
}

void lineccdview::GetOffset()
{

    QByteArray ba((char*)cmd, 5);
    ba[1] =  0x24;
    ba[4] = ba[0]+ba[1]+ba[2]+ba[3];

    serial->writeMyCom(ba);
}

void lineccdview::GetSmooth()
{

    QByteArray ba((char*)cmd, 5);
    ba[1] =  0x26;
    ba[4] = ba[0]+ba[1]+ba[2]+ba[3];

    serial->writeMyCom(ba);
}

void lineccdview::SetFilterLevel()
{

    QByteArray ba((char*)cmd, 5);
    quint8 FilterLevel = ui->lineEdit_Filterlevel->text().toInt();
    ba[1] =  0x20;
    ba[2] = FilterLevel;
    ba[4] = ba[0]+ba[1]+ba[2]+ba[3];
    serial->writeMyCom(ba);
}

void lineccdview::SetInterval()
{

    QByteArray ba((char*)cmd, 5);
    ba[1] =  0x08;
    quint16 interval = ui->lineEdit_interval->text().toInt();
    ba[2] = interval>>8;
    ba[3] = interval;
    ba[4] = ba[0]+ba[1]+ba[2]+ba[3];
    serial->writeMyCom(ba);
}


void lineccdview::GetInterval()
{

    QByteArray ba((char*)cmd, 5);
    ba[1] =  0x0b;
    ba[4] = ba[0]+ba[1]+ba[2]+ba[3];
    serial->writeMyCom(ba);
}

void lineccdview::Delay_MSec(unsigned int msec)

{

    QThread::msleep(100);

    QTime _Timer = QTime::currentTime().addMSecs(msec);

    while (QTime::currentTime() < _Timer)

        QThread::usleep(1000);

}

void lineccdview::on_pushButton_SetAvg_clicked()
{
    uint8_t avg = ui->lineEdit_Avg->text().toInt();
    if(avg<=0) avg = 1;
    if(avg>255)
    {
        avg = 255;
        ui->lineEdit_Avg->setText("255");
    }
    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x0c;
    ba[2] = (quint8)avg;
    serial->writeMyCom(ba);
}

void lineccdview:: SetIntUnit(QString unit)
{
    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x11;

    if(unit=="ms")
    {
        ba[2] = 0;
    }
    else
    {
        ba[2] = 1;
    }
    serial->writeMyCom(ba);

}

QString lineccdview::ToStr(int number, int size)
{
    QString str;
    str.fill('0', size);
    str.push_back(QString::number(number));
    str = str.right(size);
    return str;
}

void lineccdview::on_pushButton_fW_clicked()
{
    QMessageBox messageBox(QMessageBox::Information,
                           "Tip", "Make sure the above data is written to Flash?",
                           QMessageBox::Yes | QMessageBox::No, NULL); ;
    int result=messageBox.exec();
    if(result ==QMessageBox::No) return;

    QByteArray XArray;
    QString str = ui->textEdit->toPlainText();
    QStringList strlist = str.split('\n');
    QString key;
    QString data_h,data_l;
    XArray.append(0x81);
    XArray.append(0x14);
    quint8 crc = 0;
    quint8 h,l;
    if(strlist.length()==Pixels_ALL)
    {
        for(int i=0;i<Pixels_ALL;i++)
        {
            int tmp = strlist[i].toInt();
            key =  QString("%1").arg(tmp,4,16,QLatin1Char('0'));//转换成16进制字符，补0
            data_h = key.left(2);
            h = data_h.toUInt(nullptr,16);
            XArray.append(h);
            crc+=h;

            data_l = key.right(2);
            l = data_l.toUInt(nullptr,16);
            XArray.append(l);
            crc+=l;
        }
        XArray.append(crc);
    }
    else
    {
        QMessageBox::warning(this,"warning","Data length error!",QMessageBox::Yes);
    }

    if(serial->m_Com->isWritable())
    {
        serial->m_Com->write(XArray);
        m_writeFlash = true;
        m_flashWtrieTime = 5;
    }

}

void lineccdview::on_pushButton_fR_clicked()
{
    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x15;
    serial->writeMyCom(ba);
}

void lineccdview::on_pushButton_Clean_clicked()
{
    ui->textEdit->clear();
    m_Xdata.clear();
}

void lineccdview::on_comboBox_unit_currentIndexChanged(const QString &arg1)
{
    SetIntUnit(ui->comboBox_unit->currentText());
}

void lineccdview::on_pushButton_SetSmooth_clicked()
{
    m_smooth =ui->lineEdit_smooth->text().toInt();
    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x25;

    ba[2] = m_smooth;


    serial->writeMyCom(ba);
}

void lineccdview::on_pushButton_EarseFlash_clicked()
{
    QMessageBox messageBox(QMessageBox::Information,
                           "Tis", "Are you sure you want to wipe all your flash data? The initial parameters are restored after erasure",
                           QMessageBox::Yes | QMessageBox::No, NULL); ;
    int result=messageBox.exec();
    if(result ==QMessageBox::No) return;
    m_writeFlash = true;

    m_flashWtrieTime = 30;


    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x27;
    serial->writeMyCom(ba);
}

void lineccdview::on_pushButton_GetDark_clicked()
{
    m_BaseData = m_CCDData;
    ui->checkBox_removeDark->setEnabled(true);
}

void lineccdview::on_checkBox_removeDark_stateChanged(int arg1)
{
    if(ui->checkBox_removeDark->isChecked())
        ui->pushButton_GetDark->setEnabled(false);
    else
        ui->pushButton_GetDark->setEnabled(true);
}

void lineccdview::writeCoff_1()
{
    QString str = m_coff_1.f[0]+m_coff_1.f[1]+m_coff_1.f[2]+m_coff_1.f[3];
    QByteArray f=str.toUtf8();
    if(f.length()<64)
        return;
    QByteArray ba;
    ba.resize(69);
    ba[0] = 0x81;
    ba[1] = 0x28;
    ba[2] = 0x01;
    ba[3] = 0x40;
    for(int i=4;i<64+4;i++)
    {
        ba[i] = f[i-4];
    }
    quint8 crc = 0;
    for(int i=0;i<69;i++)
    {
        crc += ba[i];
    }
    ba[68] = crc;

    serial->writeMyCom(ba);

    Delay_MSec(100);
}

void lineccdview::readCoff_1()
{
    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x29;
    ba[2] = 0x01;
    ba[3] = 0x00;
    ba[4] = ba[0]+ba[1]+ba[2]+ba[3];
    serial->writeMyCom(ba);

    Delay_MSec(100);
}

void lineccdview::writeCoff_2()
{
    QString str = m_coff_2.f[0]+m_coff_2.f[1]+m_coff_2.f[2]+m_coff_2.f[3];
    QByteArray f=str.toUtf8();
    if(f.length()<64)
        return;
    QByteArray ba;
    ba.resize(69);
    ba[0] = 0x81;
    ba[1] = 0x28;
    ba[2] = 0x02;
    ba[3] = 0x40;
    for(int i=4;i<64+4;i++)
    {
        ba[i] = f[i-4];
    }
    quint8 crc = 0;
    for(int i=0;i<69;i++)
    {
        crc += ba[i];
    }
    ba[68] = crc;

    serial->writeMyCom(ba);

    Delay_MSec(100);
}

void lineccdview::readCoff_2()
{
    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x29;
    ba[2] = 0x02;
    ba[3] = 0x00;
    ba[4] = ba[0]+ba[1]+ba[2]+ba[3];
    serial->writeMyCom(ba);

    Delay_MSec(100);
}

void lineccdview::writeCoff_3()
{
    QString str = m_coff_3.f[0]+m_coff_3.f[1]+m_coff_3.f[2]+m_coff_3.f[3];
    QByteArray f=str.toUtf8();
    if(f.length()<64)
        return;
    QByteArray ba;
    ba.resize(69);
    ba[0] = 0x81;
    ba[1] = 0x28;
    ba[2] = 0x03;
    ba[3] = 0x40;
    for(int i=4;i<64+4;i++)
    {
        ba[i] = f[i-4];
    }
    quint8 crc = 0;
    for(int i=0;i<69;i++)
    {
        crc += ba[i];
    }
    ba[68] = crc;

    serial->writeMyCom(ba);

    Delay_MSec(100);
}

void lineccdview::readCoff_3()
{
    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x29;
    ba[2] = 0x03;
    ba[3] = 0x00;
    ba[4] = ba[0]+ba[1]+ba[2]+ba[3];
    serial->writeMyCom(ba);

    Delay_MSec(100);
}

void lineccdview::on_radioButton_pixels_clicked()
{
    if(ui->radioButton_pixels->isChecked())
    {
        m_CCDData_Pixels.clear();
        for(int i=0;i<Pixels_Effective;i++)
            m_CCDData_Pixels.append(i);
        ui->plot->graph(0)->setData(m_CCDData_Pixels, m_CCDData);
        ui->plot->replot();
    }
}

void lineccdview::on_radioButton_wavelength_clicked()
{
    if(ui->radioButton_wavelength->isChecked())
    {
        m_CCDData_Pixels.clear();
        for(int i=0;i<Pixels_Effective;i++)
        {
            double wavelength = m_coff_1.f[0].toDouble()*i*i*i+m_coff_1.f[1].toDouble()*i*i+m_coff_1.f[2].toDouble()*i+m_coff_1.f[3].toDouble();
            m_CCDData_Pixels.append(wavelength);
        }
        ui->plot->graph(0)->setData(m_CCDData_Pixels, m_CCDData);
        ui->plot->replot();
    }
}

void lineccdview::on_radioButton_raman_clicked()
{
    if(ui->radioButton_raman->isChecked())
    {
        m_CCDData_Pixels.clear();
        for(int i=0;i<Pixels_Effective;i++)
        {
            double ramanshift = m_coff_2.f[0].toDouble()*i*i*i+m_coff_2.f[1].toDouble()*i*i+m_coff_2.f[2].toDouble()*i+m_coff_2.f[3].toDouble();
            m_CCDData_Pixels.append(ramanshift);
        }
        ui->plot->graph(0)->setData(m_CCDData_Pixels, m_CCDData);
        ui->plot->replot();
    }
}

void lineccdview::on_radioButton_wavenumber_clicked()
{
    if(ui->radioButton_wavenumber->isChecked())
    {
        m_CCDData_Pixels.clear();
        for(int i=0;i<Pixels_Effective;i++)
        {
            double wavenumber = m_coff_3.f[0].toDouble()*i*i*i+m_coff_3.f[1].toDouble()*i*i+m_coff_3.f[2].toDouble()*i+m_coff_3.f[3].toDouble();
            m_CCDData_Pixels.append(wavenumber);
        }
        ui->plot->graph(0)->setData(m_CCDData_Pixels, m_CCDData);
        ui->plot->replot();
    }
}


void lineccdview::on_pushButton_SetInterval_clicked()
{
    SetInterval();
}



void lineccdview::on_pushButton_filter_clicked()
{
    SetFilterLevel();
}

void lineccdview::on_pushButton_Bandrate_read_clicked()
{
    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x16;
    serial->writeMyCom(ba);
}
