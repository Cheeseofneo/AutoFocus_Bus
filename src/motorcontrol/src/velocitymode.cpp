#include "velocitymode.h"
#include "ui_velocitymode.h"

#define STATION_ADDRESS 8
#define MOTOR_RATED_SPEED 155

velocitymode::velocitymode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::velocitymode)
{
    ui->setupUi(this);
    this->setWindowTitle("Connect");
    this->setFixedSize(600,650);

    dial* mydial = new dial(this);
    mydial->setFixedSize(300,300);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(ui->parameter,0,Qt::AlignHCenter);
    layout->addWidget(mydial,0,Qt::AlignHCenter);
    this->setLayout(layout);

    m_mainwindow = (MainWindow*)parentWidget();

    connect(ui->checkBoxconnect,SIGNAL(stateChanged(int)),this,SLOT(checkconnect(int)));
    //connect(ui->horizontalSlider, &QSlider::valueChanged, ui->mydial, &dial::valueChanged);

    Initial_Setting();
}

velocitymode::~velocitymode()
{
    delete ui;
}

void velocitymode::Initial_Setting(){

    QStringList dir={"+z","-z"};
    ui->comboBoxDir->addItems(dir);
    ui->spinBoxvspin->setRange(0,MOTOR_RATED_SPEED);
//    ui->spinBoxvspinlim->setMaximum(MOTOR_RATED_SPEED);
//    ui->spinBoxvspin->setMaximum
    ui->spinBoxvspinlim->setMaximum(std::min(MOTOR_RATED_SPEED,ui->spinBoxvspin->value()));

    ui->checkBoxconnect->setChecked(true);
}

void velocitymode::WriteCommand(int stationAddress,int startAddress, QVector<quint8> command){
    if (!m_mainwindow->modbusDevice)
    {
        QMessageBox::information(NULL,  "Title",  "尚未连接从站设备");
        return;
    }

    QModbusDataUnit::RegisterType type=QModbusDataUnit::HoldingRegisters;
    QModbusDataUnit writeUnit = QModbusDataUnit(type,startAddress, command.size()/2);

    for(int i=0; i<command.size(); i+=2)
    {
        quint16 temp=(command.at(i)<<8) | command.at(i+1);
        writeUnit.setValue(i/2, temp);
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

void velocitymode::ReadRequest(int startAddress,quint16 numberOfEntries)
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
void velocitymode::ReadSerialData()
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

void velocitymode::checkconnect(int state){
    if(state==Qt::Unchecked)
    {
        if (m_mainwindow->modbusDevice->state() == QModbusDevice::ConnectedState)
        {
            ui->checkBoxconnect->setChecked(true);
        }
        else
        {
            if (QMessageBox::Ok ==
                QMessageBox::question(this, tr("提示"),
                    QString(tr("串口 %1 并没有打开, 是否要打开串口 %2 ?"))
                    .arg(m_mainwindow->ui->comboBoxPort->currentText(), m_mainwindow->ui->comboBoxPort->currentText()),
                                      QMessageBox::Ok, QMessageBox::Cancel))
            {
                m_mainwindow->on_actionConnect_triggered();
            }
            ui->checkBoxconnect->setChecked(true);
        }
    }
}

void velocitymode::on_pushButtonstart_clicked(){

    quint16 speed=ui->spinBoxvspin->value();

    // unsigned char startmodesetup[6]={0x08,0x06,0x10,0x0a,0x00,0x01};
    // unsigned char interactactivate[6]={0x08,0x06,0x10,0x8c,0x00,0x02};
    // unsigned char velocitylimit[6]={0x08,0x06,0x10,0x8d,0x00,0x0f};
    // unsigned char velocitysetup[11]={0x08,0x10,0x10,0x02,0x00,0x02,0x04,0x00,0x00,0x00,0x00};

    QVector<quint8> motor;
    motor.push_back(speed >> 8);
    motor.push_back(speed & 0xFF);
    motor.push_back(0x00);
    motor.push_back(0x00);

    WriteCommand(STATION_ADDRESS,0x100a,{0x00,0x01});
    WriteCommand(STATION_ADDRESS,0x108c,{0x00,0x02});
    WriteCommand(STATION_ADDRESS,0x108d,{0x00,0x0f});
    WriteCommand(STATION_ADDRESS,0x1002,motor);

    int delay_msec= speed/10;
    QTime _timer = QTime::currentTime().addMSecs(delay_msec);
    while( QTime::currentTime()<_timer)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 500);

    ReadRequest(0x1306,2); // 读取当前速度 来动态显示dial
}

void velocitymode::on_pushButtonend_clicked(){

    // 速度设置为0
    WriteCommand(STATION_ADDRESS,0x1002,{0x00,0x00,0x00,0x00});
}

QVector<quint8> velocitymode::crc16_modbus(unsigned char* data,int len){

    quint16 crc=0XFFFF;
    uint8_t temp;
    for(int i=0;i<len;i++)
    {
        temp=data[i];
        crc^=temp;
        for(int j=0;j<8;j++){
            if(crc&0X0001){
                crc>>=1;
                crc^=0Xa001;
            }
            else
                crc>>=1;
        }
    }
    uint8_t wcrc[2];
    wcrc[0] = crc & 0xFF;// high
    wcrc[1] = crc >> 8; //low
    QVector<quint8> command;
    for(int i=4;i<len;i++){
        command.push_back(data[i]);
    }
    command.push_back(wcrc[0]);
    command.push_back(wcrc[1]);
    qDebug()<<command;
    return command;
}










