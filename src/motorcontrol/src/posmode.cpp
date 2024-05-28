#include "posmode.h"
#include "ui_posmode.h"

#define STATION_ADDRESS 8

DataCaptureThread::DataCaptureThread( QModbusClient *device, QString imagesavapath, QString lineccdsavepath, QObject *parent)
    : QThread(parent), m_device(device), m_imagesavapath(imagesavapath), m_lineccdsavepath(lineccdsavepath)
{
    stopped = false;
}

void DataCaptureThread::run(){

    int loops = 0;
    QMessageBox msgBox(QMessageBox::Critical,
                   "错误",
                   "图像采集失败",
                   QMessageBox::Ok);
    QMessageBox msgBox2(QMessageBox::Critical,
                   "错误",
                   "线阵CCD数据采集失败",
                   QMessageBox::Ok);
    
    while( loops<stepNum && !stopped){ 
        
        // 采集图像和lineccd数据
        int ret = LB_Grab().grabImg(1,true);        
        if(ret == 0){
            msgBox.exec();
            break;
        }
        int ret2 = lineccdcapture(loops);
        if(ret2 == 0){
            msgBox.exec();
            break;
        }
        msleep(2000);

        // 步进移动
        quint32 next = static_cast<quint32>(offset+loops*step);
        WriteCommand(STATION_ADDRESS,0x1008,{static_cast<quint16>(next & 0x0000ffff),static_cast<quint16>(next>>16)}); // 触发移动
        msleep(1000);
        loops++;
    }
    return;
}

void DataCaptureThread::stop(){
    stopped = true;
}

void DataCaptureThread::capturethread(QVector<quint16> data){
    offset = data[0];
    step = data[2];
    stepNum = round((data[1]-data[0])/data[2]);
}

void DataCaptureThread::receiveccddata(QVector<double> data){
    m_CCDData = data;
}

int DataCaptureThread::lineccdcapture(int index){
    
    // 初始化filename变量
    QString filename =m_lineccdsavepath + QString::number(index) + ".txt";
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        QMessageBox::warning(nullptr,"warning","can't open the path of lineCCD data!",QMessageBox::Yes);
        return -1;
    }
    QTextStream in(&file);
    // Save the data
    for(int i = 0;i<m_CCDData.length();i++)
    {
        in<<QString::number(m_CCDData[i])<<"\n";
    }
    file.close();
    return 0;
}

void DataCaptureThread::WriteCommand(int stationAddress,int startAddress, QVector<quint16> command){
    
    QModbusDataUnit writeUnit = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, startAddress, command.size());

    for(int i=0; i<command.size(); i++)
    {
        writeUnit.setValue(i, command.at(i));
    }
    if (auto *reply = m_device->sendWriteRequest(writeUnit,stationAddress))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]() {
                reply->deleteLater();
            });
        }
        else
        {
            reply->deleteLater();
        }
    }
}

// -----------------------------------------------------

posmode::posmode(QWidget *parent):
    QDialog(parent),
    ui(new Ui::posmode)
{
    ui->setupUi(this);
    m_mainwindow = (MainWindow*)parentWidget();
    m_capturethread = new DataCaptureThread(m_mainwindow->modbusDevice,"/home/linaro/","/home/linaro/",this);

    connect(ui->checkBoxtimedelay,SIGNAL(stateChanged(int)),this,SLOT(timedelay()));
    connect(ui->lineEditstart,&QLineEdit::textEdited, ui->labelbarstart, QLabel::setText);
    connect(ui->lineEditend,&QLineEdit::textEdited, ui->labelbarend, QLabel::setText);
    connect(this,SIGNAL(readycapture(int)),m_capturethread,SLOT(capturethread(QVector<quint16> data)));
    connect(this,SIGNAL(stopcapture()),m_capturethread,SLOT(stop()));
    connect(m_mainwindow->m_widget,SIGNAL(ThreadCCDdata(QVector<double>)),m_capturethread,SLOT(receiveccddata(QVector<double> data)));

//    QVBoxLayout *layout = new QVBoxLayout(this);
//    layout->addWidget(ui->groupBoxstep, 0, Qt::AlignHCenter);
//    layout->addWidget(ui->groupBoxonepos,0,Qt::AlignHCenter);
//    this->setLayout(layout);
}

posmode::~posmode()
{
    delete ui;
}

void posmode::Initial_Setting()
{
    QStringList dir={"+z","-z"};
    ui->comboBoxdir->addItems(dir);

    ui->labelbarstart->setText("start");
    ui->labelbarend->setText("end");
    ui->checkBoxtimedelay->setChecked(false);
    ui->checkBoxstart->setChecked(true);
    // ui->checkBoxcapture->setChecked(false);
    ui->lineEditcurpos->setReadOnly(true);
 

    //设置格式
    ui->lineEditstart->setValidator(new QRegExpValidator(QRegExp("^(-?/d+)(/./d+)?$")));
    ui->lineEditend->setValidator(new QRegExpValidator(QRegExp("^(-?/d+)(/./d+)?$")));
    ui->lineEditstep->setValidator(new QRegExpValidator(QRegExp("^(-?/d+)(/./d+)?$")));

    ui->progressBar->setValue(0);
    ui->progressBar->setAlignment(Qt::AlignHCenter);
}

void posmode::WriteCommand(int stationAddress,int startAddress, QVector<quint16> command){
    if (!m_mainwindow->modbusDevice)
    {
        QMessageBox::information(NULL,  "Title",  "尚未连接从站设备");
        return;
    }

    QModbusDataUnit writeUnit = QModbusDataUnit(QModbusDataUnit::HoldingRegisters,startAddress, command.size());
    for(int i=0; i<command.size(); i++)
    {
        writeUnit.setValue(i, command.at(i));
    }

    if (auto *reply = m_mainwindow->modbusDevice->sendWriteRequest(writeUnit,stationAddress))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]() {
                if (reply->error() == QModbusDevice::ProtocolError) {
                    qDebug() << QString("Write response error: %1 (Mobus exception: 0x%2)")
                                    .arg(reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16);
                } else if (reply->error() != QModbusDevice::NoError) {
                    qDebug() << QString("Write response error: %1 (code: 0x%2)").
                                arg(reply->errorString()).arg(reply->error(), -1, 16);
                }
                reply->deleteLater();
            });
        }
        else
        {
            reply->deleteLater();
        }
    }
    else
    {
        qDebug() << QString(("Write error: ") + m_mainwindow->modbusDevice->errorString());
    }
}

void posmode::ReadRequest(int startAddress,quint16 numberOfEntries)
{
    if (!m_mainwindow->modbusDevice)
    {
        QMessageBox::information(NULL,  "Title",  "尚未连接从站设备");
        return;
    }

    QModbusDataUnit::RegisterType type=QModbusDataUnit::HoldingRegisters;
    QModbusDataUnit readUnit=QModbusDataUnit(type, startAddress, numberOfEntries);

    if (auto *reply = m_mainwindow->modbusDevice->sendReadRequest(readUnit, STATION_ADDRESS))
    {
        if (!reply->isFinished())
            connect(reply, &QModbusReply::finished, this, &ReadSerialData);
        else
            delete reply; // broadcast replies return immediately
    }
    else
    {
        m_mainwindow->statusBar()->showMessage(tr("Read error: ") + m_mainwindow->modbusDevice->errorString(), 5000);
    }

}

//从串口接收数据
void posmode::ReadSerialData()
{
    auto reply = qobject_cast<QModbusReply *>(sender());
    if (!reply)
        return;

    if (reply->error() == QModbusDevice::NoError)
    {
        const QModbusDataUnit unit = reply->result();

        for (int i = 0, total = int(unit.valueCount()); i < total; ++i)
        {
            QString valuereceive= QString::number(unit.value(i)
                                                   ,unit.registerType() <= QModbusDataUnit::Coils ? 10 : 16);
            qDebug()<<valuereceive;
            const QString entry = tr("Address: %1, Value: %2").arg(unit.startAddress() + i)
                                      .arg(valuereceive);
            qDebug()<<entry;

        }
    }
    else if (reply->error() == QModbusDevice::ProtocolError)
    {
        m_mainwindow->statusBar()->showMessage(tr("Read response error: %1 (Mobus exception: 0x%2)").
                                               arg(reply->errorString()).
                                               arg(reply->rawResult().exceptionCode(), -1, 16), 5000);
    }
    else
    {
        m_mainwindow->statusBar()->showMessage(tr("Read response error: %1 (code: 0x%2)").
                                               arg(reply->errorString()).
                                               arg(reply->error(), -1, 16), 5000);
    }

    reply->deleteLater();
    return;
}

void posmode::on_pushButtonbackzero_clicked(){

    QVector<quint16> startenable{0x000a};
    QVector<quint16> triggermode{0x0100};
    WriteCommand(STATION_ADDRESS,0x1000,startenable);
    WriteCommand(STATION_ADDRESS,0x10EA,triggermode);

    // 设置时间循环，循环检测位置

}

void posmode::back2zero(){

    QVector<quint16> triggermode{0x0200};  //命令触发回零
    QVector<quint16> setmode{0x0002}; // 设置回零模式为2
    QVector<quint16> set_v0{0x0064};
    QVector<quint16> set_v1{0x0014};
    QVector<quint16> zero_offset{0x0000};
    QVector<quint16> trigger{0x0010}; // 触发回零
    
    WriteCommand(STATION_ADDRESS,0x10EA,triggermode);
    WriteCommand(STATION_ADDRESS,0x10ED,setmode);
    WriteCommand(STATION_ADDRESS,0x10EB,set_v0);
    WriteCommand(STATION_ADDRESS,0x10EC,set_v1);
    WriteCommand(STATION_ADDRESS,0x10EE,zero_offset);
    WriteCommand(STATION_ADDRESS,0x100C,trigger); 

}

void posmode::on_pushButtonstartstep_clicked(){

    QString start=ui->lineEditstart->text(),end=ui->lineEditend->text(),step=ui->lineEditstep->text();
    double endpos,startpos,step_d;
    if(start.isEmpty() || end.isEmpty() || step.isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("参数不全！"),QMessageBox::Ok);
    }
    else{
        startpos=start.toDouble(),endpos=end.toDouble(),step_d=step.toInt();
        ui->labelbarstart->setNum(startpos);
        ui->labelbarend->setNum(endpos);
    }
    QVector<quint16> transdata;
    transdata.push_back(static_cast<quint16>(postopulse(startpos)));
    transdata.push_back(static_cast<quint16>(postopulse(endpos)));
    transdata.push_back(static_cast<quint16>(step_d));

    QVector<quint16> modeassign{0x0000};
    QVector<quint16> clearpos{0x0002};
    QVector<quint16> movestartpos;
    movestartpos.push_back(static_cast<quint16>(postopulse(startpos)));

    // 首先移动到start，然后循环
    WriteCommand(STATION_ADDRESS,0x10D0,clearpos);
    WriteCommand(STATION_ADDRESS,0x10D9,modeassign); // 脉冲清除模式
    WriteCommand(STATION_ADDRESS,0x1008,movestartpos);
    

    emit readycapture(transdata);

}

void posmode::on_pushButtonendstep_clicked(){
    
    
    emit stopcapture();
    

}

void posmode::on_pushButtonstartp2p_clicked(){
    QList<quint8> startenable{0x00,0x00};
}

void posmode::on_pushButtonendp2p_clicked(){

}

void posmode::timedelay(){
    if(!ui->checkBoxtimedelay->isChecked()){
        ui->spinBoxtimedelay->setReadOnly(true);
    }
    else{

    }
}

int posmode::postopulse(double pos){

    // pulse 和 pos的关系
    int lead = 7; // mm
    int gear = 24;
    int encoder_strip = 720;
    int mag = 4;
    double mm_per_pulse = lead/(encoder_strip*mag*gear);
    return static_cast<int>(std::round(pos/mm_per_pulse));
}
