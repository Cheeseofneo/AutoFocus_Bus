#include "mainwindow.h"
#include "ui_mainwindow.h"

#define STATION_ADDRESS 8

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    this->setWindowTitle("Autofocus");
    this->setMinimumSize(1000,800);
    this->setMaximumSize(1920,1080);

    // 线阵CCD相关控件
    m_widget = new lineccdview;
    ui->stackedWidget->addWidget(m_widget);
    ui->stackedWidget->setCurrentWidget(m_widget);

    // 电机运动模式设置
    m_vmode = new velocitymode(this);
    m_pmode = new posmode(this);
    modbusDevice = new QModbusRtuSerialMaster(this);
    pollTimer = new QTimer;

    // 线程、控件关联管理
    //connect(m_widget,SIGNAL(ThreadCCDdata(QVector<double>)),this,SLOT(ReceiveCCDdata(QVector<double>)) );
    //QLoggingCategory::setFilterRules(QStringLiteral("qt.modbus* = true"));
    //connect(ui->listWidget, &QListWidget::itemClicked,this, &MyWindow::handleItemClicked);

    InitialSetting();

    // 电机通信初始化设置控件
    dialog* Commtype = new dialog(this);
    Commtype->setWindowTitle("Motor Connect");
    Commtype->setFixedSize(500,600);
    Commtype->setWindowFlags(Qt::Dialog);
    Commtype->exec();

    //exec()后对象不会被销毁 检查是否为空
    QFileInfo checkFile(Commtype->camera_path);
    if (checkFile.exists() && checkFile.isDir()) {
       image_savepath = Commtype->camera_path;
    }else {
       QMessageBox::information(this,tr("Error"),tr("相机图像存储路径不存在！"),QMessageBox::Ok);
    }

    QFileInfo checkFile2(Commtype->lineccd_path);
    if (checkFile2.exists() && checkFile2.isDir()) {
       lineccddata_savepath = Commtype->lineccd_path;
    }else {
       QMessageBox::information(this,tr("Error"),tr("线阵CCD数据存储路径不存在！"),QMessageBox::Ok);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitialSetting()
{
    //填充串口号组合框
    SearchSerialPorts();

    // 设置工具栏状态
    ui->actiondisplace->setEnabled(false);
    ui->actionvelocity->setEnabled(false);
    ui->actionfocus->setEnabled(false);
    ui->actionSave->setEnabled(false);

    //填充串口波特率
    QStringList baud={"4800","9600","14400","19200","28800","38400","56000","57600","115200","128000","230400","256000"};
    ui->comboBoxBaud->addItems(baud);

    //填充串口数据位
    ui->comboBoxData->addItem("7位");
    ui->comboBoxData->addItem("8位");
    ui->comboBoxData->addItem("9位");

    //填充串口校验位
    ui->comboBoxParity->addItem("无校验");
    ui->comboBoxParity->addItem("奇校验");
    ui->comboBoxParity->addItem("偶校验");

    //填充串口停止位
    ui->comboBoxStop->addItem("1位");
    ui->comboBoxStop->addItem("1.5位");
    ui->comboBoxStop->addItem("2位");

    //填充寄存器类型
    ui->comboBoxDataType->addItem("0 Coils");
    ui->comboBoxDataType->addItem("1 Input Status");
    ui->comboBoxDataType->addItem("2 Input Registers");
    ui->comboBoxDataType->addItem("3 Holding Registers");
    ui->comboBoxDataType->setCurrentIndex(3);

    //填充报文格式
    ui->comboBoxFormat->addItem("Modbus-RTU");
    ui->comboBoxFormat->addItem("Modbus-ASCII");
    ui->comboBoxFormat->setCurrentIndex(0);

    // 从站地址
    ui->spinBoxStation->setValue(STATION_ADDRESS);

    //设置界面操作的初始状态
    ui->spinBoxInterval->setValue(1000);
    ui->checkBoxAuto->setChecked(true);

    //成员变量赋值

}

//搜索串口
void MainWindow::SearchSerialPorts()
{
    ui->comboBoxPort->clear();

    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        ui->comboBoxPort->addItem(info.portName());
    }
}

//写数据请求
void MainWindow::WriteCommand(QList<quint16> values)
{
    if (!modbusDevice)
    {
        QMessageBox::information(this, "Error",  "尚未连接从站设备");
        return;
    }

    QModbusDataUnit::RegisterType type; //设置为holdingregister

    switch(ui->comboBoxDataType->currentIndex())
    {
        case 0:type=QModbusDataUnit::Coils;break;
        case 1:type=QModbusDataUnit::DiscreteInputs;break;
        case 2:type=QModbusDataUnit::InputRegisters;break;
        case 3:type=QModbusDataUnit::HoldingRegisters;break;
        default:type=QModbusDataUnit::Invalid;
    }

    //位数据（Coils）表示单个开关量的状态，可以表示开/关、真/假等状态，只能读取和写入单个位，使用功能码 01H 或 05H
    //离散量输入（Discrete Inputs）:表示输入的状态，只能读取，不能写入，使用功能码 02H 可以对 Discrete Inputs 进行读操作。
    //位无符号整数（Input Registers）：表示无符号的16位整数，只能读取，使用功能码 04H 可以对 Input Registers 进行读操作。
    //位有符号整数（Holding Registers）：表示有符号的 16 位整数，可以读取和写入，使用功能码 03H 或 06H

    int startAddress = ui->spinBoxStartWrite->value();
    // Q_ASSERT(startAddress >= 0 && startAddress < 10);

    QModbusDataUnit writeUnit = QModbusDataUnit(type,startAddress, values.size());
    for(int i=0; i<values.size(); i++)
    {
        writeUnit.setValue(i, values.at(i));
    }

    //serverEdit发给slave的ID
    if (auto *reply = modbusDevice->sendWriteRequest(writeUnit,ui->spinBoxStation->value()))
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
        qDebug() << QString(("Write error: ") + modbusDevice->errorString());
    }
}

void MainWindow::WriteCommand(int stationAddress,int startAddress, QVector<quint16> command){
    if (!modbusDevice)
    {
        QMessageBox::information(this,  "Error",  "尚未连接从站设备");
        return;
    }

    QModbusDataUnit::RegisterType type=QModbusDataUnit::HoldingRegisters;
    QModbusDataUnit writeUnit = QModbusDataUnit(type,startAddress, command.size());

    for(int i=0; i<command.size(); i++)
    {
        writeUnit.setValue(i, command.at(i));
    }

    if (auto *reply = modbusDevice->sendWriteRequest(writeUnit,stationAddress))
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
        qDebug() << QString(("Write error: ") + modbusDevice->errorString());
    }
}

//读数据请求
void MainWindow::ReadRequest()
{
    if (!modbusDevice)
    {
        QMessageBox::information(this, "Error",  "尚未连接从站设备");
        return;
    }

    QModbusDataUnit::RegisterType type;

    switch(ui->comboBoxDataType->currentIndex())
    {
        case 0:type=QModbusDataUnit::Coils;break;
        case 1:type=QModbusDataUnit::DiscreteInputs;break;
        case 2:type=QModbusDataUnit::InputRegisters;break;
        case 3:type=QModbusDataUnit::HoldingRegisters;break;
        default:type=QModbusDataUnit::Invalid;
    }

    int startAddress = ui->spinBoxStartRead->value();// 设置为0x08
    Q_ASSERT(startAddress >= 0 && startAddress < 10);

    // do not go beyond 10 entries
    quint16 numberOfEntries = qMin(quint16(ui->spinBoxNumberRead->value()), quint16(10 - startAddress));
    QModbusDataUnit readUnit=QModbusDataUnit(type, startAddress, numberOfEntries);

    statusBar()->clearMessage();

    if (auto *reply = modbusDevice->sendReadRequest(readUnit, ui->spinBoxStation->value()))
    {
        if (!reply->isFinished())
            connect(reply, &QModbusReply::finished, this, &MainWindow::ReadSerialData);
        else
            delete reply; // broadcast replies return immediately
    }
    else
    {
        statusBar()->showMessage(tr("Read error: ") + modbusDevice->errorString(), 5000);
    }

}

//从串口接收数据
void MainWindow::ReadSerialData()
{
    auto reply = qobject_cast<QModbusReply *>(sender());
    if (!reply)
        return;

    if (reply->error() == QModbusDevice::NoError)
    {
        const QModbusDataUnit unit = reply->result();

        for (int i = 0, total = int(unit.valueCount()); i < total; ++i)
        {
            const QString entry = tr("Address: %1, Value: %2").arg(unit.startAddress() + i)
                                     .arg(QString::number(unit.value(i),
                                          unit.registerType() <= QModbusDataUnit::Coils ? 10 : 16));
            ui->textBrowser->append(entry);

            if((unit.startAddress() + i)<8)
            {
                values[(unit.startAddress() + i)]=unit.value(i);
            }
        }
    }
    else if (reply->error() == QModbusDevice::ProtocolError)
    {
        statusBar()->showMessage(tr("Read response error: %1 (Mobus exception: 0x%2)").
                                    arg(reply->errorString()).
                                    arg(reply->rawResult().exceptionCode(), -1, 16), 5000);
    }
    else
    {
        statusBar()->showMessage(tr("Read response error: %1 (code: 0x%2)").
                                    arg(reply->errorString()).
                                    arg(reply->error(), -1, 16), 5000);
    }

    reply->deleteLater();
}

void MainWindow::ReceiveCCDdata(QVector<double> data){

    m_CCDData = data;
}

//退出程序
void MainWindow::on_actionExit_triggered()
{
    this->close();
}

//串口连接
void MainWindow::on_actionConnect_triggered()
{
    if (!modbusDevice)
        return;

    modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,ui->comboBoxPort->currentText());
    modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,
                                         ui->comboBoxBaud->currentText().toInt());

    switch(ui->comboBoxParity->currentIndex())                   //设置奇偶校验
    {
        case 0: modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,
                                                     QSerialPort::NoParity);break;
        default: break;
    }

    switch(ui->comboBoxData->currentIndex())                   //设置数据位数
    {
        case 1:modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,QSerialPort::Data8);break;
        default: break;
    }

    switch(ui->comboBoxStop->currentIndex())                     //设置停止位
    {
        case 1: modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::OneStop);break;
        case 2: modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::TwoStop);break;
        default: break;
    }

    modbusDevice->setTimeout(1000);
    modbusDevice->setNumberOfRetries(3);

    if (modbusDevice->connectDevice())
    {
        //开启自动读取
        if(ui->checkBoxAuto->isChecked())
        {
            connect(pollTimer,&QTimer::timeout, this, &MainWindow::ReadRequest);
            pollTimer->setInterval(ui->spinBoxInterval->value());
            pollTimer->start();
        }

        //连接槽函数
        //QObject::connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::ReadSerialData);

        // 设置控件可否使用
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionRefresh->setEnabled(false);
        ui->actionmotorenable->setEnabled(true);
        ui->actiondisable->setEnabled(true);
        ui->actiondisplace->setEnabled(true);
        ui->actionvelocity->setEnabled(true);
    }
    else    //打开失败提示
    {
        QMessageBox::information(this,tr("错误"),tr("连接从站失败！"),QMessageBox::Ok);
    }
}

//断开连接
void MainWindow::on_actionDisconnect_triggered()
{
    modbusDevice->disconnectDevice();
    pollTimer->stop();
    // 设置控件可否使用
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionRefresh->setEnabled(true);
    ui->actionmotorenable->setEnabled(false);
    ui->actiondisable->setEnabled(false);
    ui->actiondisplace->setEnabled(false);
    ui->actionvelocity->setEnabled(false);
}

//刷新串口
void MainWindow::on_actionRefresh_triggered()
{
    //填充串口号组合框
    SearchSerialPorts();
}

//参数配置
//void MainWindow::on_actionConfig_triggered()
//{
//    // 可以用作电机参数配置
//}

// 对焦
void MainWindow::on_actionfocus_triggered(){

//    int pos = ;
//    DataProcess().offset_calculate();
//    WriteCommand();

}

//报文保存
void MainWindow::on_actionSave_triggered()
{

    ui->actionSave->setEnabled(false);
    ui->actionSave->setDisabled(false);

//    if(ui->textBrowser->toPlainText().isEmpty()){
//        QMessageBox::information(this, "提示消息", tr("貌似还没有数据! 您需要在发送编辑框中输入要发送的数据"), QMessageBox::Ok);
//    }


    // command保存
    //    QString filename = QFileDialog::getSaveFileName(this, tr("保存为"), tr("未命名.txt"),tr("Text files (*.txt)"));
    //    QFile file(filename);
    //    if(file.fileName().isEmpty()){
    //     return;
    //    }

    //    //如果打开失败则给出提示并退出函数
    //    if(!file.open(QFile::WriteOnly | QIODevice::Text)){
    //        QMessageBox::warning(this, tr("保存文件"), tr("打开文件 %1 失败, 无法保存\n%2").arg(filename).arg(file.errorString()), QMessageBox::Ok);
    //        return;
    //    }
    //    //写数据到文件
    //    QTextStream out(&file);
    //    out<<ui->textBrowser->toPlainText();
    //    file.close();


    // lineCCD save
    QString selfilter;
    QString lineccdfileName = QFileDialog::getSaveFileName(this,
                           tr("LineCCD Save Data"),
                           "",
                           tr("*.txt;;*.csv"),&selfilter);

    if (!lineccdfileName.isNull())
    {
        QFile file(lineccdfileName);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Truncate))
        {
            QMessageBox::warning(this,"warning","can't open",QMessageBox::Yes);
        }
        QTextStream in(&file);
        if(selfilter==("*.txt"))
        {
            for(int i = 0;i<m_CCDData.length();i++)
            {
                in<<QString::number(m_CCDData[i])<<"\n";
            }
        }
        else if(selfilter==("*.csv"))
        {
            for(int i = 0;i<m_CCDData.length();i++)
            {
                in<<QString::number(m_CCDData[i])<<"\n";
            }
        }
        file.close();
    }
    else
    {
        QMessageBox::warning(this,"warning","can't open",QMessageBox::Yes);
    }

    ui->actionSave->setEnabled(true);
}

void MainWindow::on_actionmotorenable_triggered()
{
    ui->actiondisplace->setEnabled(true);
    ui->actionvelocity->setEnabled(true);
    ui->actionfocus->setEnabled(true);

    QVector<quint16> startenable{0x000a};
    WriteCommand(STATION_ADDRESS,0x1000,startenable);

}

void MainWindow::on_actiondisable_triggered()
{
    ui->actiondisplace->setEnabled(false);
    ui->actionvelocity->setEnabled(false);
    ui->actionfocus->setEnabled(false);

    QVector<quint16> closeenable{0x0001};
    QVector<quint16> triggermode{0x0100};  //上电自动回零
    QVector<quint16> startpos{0x0000,0x0000}; // 设置回零模式为36
    
    // 回到原点 并将回零设置为上电触发
    WriteCommand(STATION_ADDRESS,0x1008,startpos);
    WriteCommand(STATION_ADDRESS,0x10EA,triggermode);
    WriteCommand(STATION_ADDRESS,0x1000,closeenable);
}

//速度环
void MainWindow::on_actionvelocity_triggered()
{
    QVector<quint16> velocitymode{0x0001};
    WriteCommand(STATION_ADDRESS,0x100a,velocitymode);
    m_vmode->setWindowTitle("速度环");
    // m_vmode->setWindowModality(Qt::WindowModal);
    m_vmode->show();
}

//位置环
void MainWindow::on_actiondisplace_triggered()
{
    QVector<quint16> posmode{0x0000};
    WriteCommand(STATION_ADDRESS,0x100a,posmode);
    m_pmode->setWindowTitle("位置环");
    m_pmode->setFixedSize(600,624);
    // m_pmode->setWindowModality(Qt::WindowModal);
    m_pmode->show();
}

// 线阵ccd传感器配置
void MainWindow::on_actionchannel_config_triggered()
{
    m_widget->m_DlgConfig->setWindowTitle("LineCCD配置");
    m_widget->m_DlgConfig->show();
}

//相机配置
void MainWindow::on_actioncamera_triggered()
{

}

//手动读取
void MainWindow::on_pushButtonRead_clicked()
{
    ReadRequest();
}

//手动写入
void MainWindow::on_pushButtonWrite_clicked()
{
    QList<quint16> values;

    QStringList str1=ui->lineEditWriteValue->text().split(",");
    //qDebug()<<str1.size();
    //qDebug()<<ui->spinBoxNumberWrite->value();

    for(int i=0;i<ui->spinBoxNumberWrite->value();i++)
    {
        values.append(str1[i].toUShort());
    }

    //qDebug()<<values.size();
    WriteCommand(values);
}

//手动发送
void MainWindow::on_pushButtonSend_clicked()
{

}


//手自动变换
void MainWindow::on_checkBoxAuto_clicked(bool checked)
{
    if(checked)     //自动循环发送
    {
        if (modbusDevice->state() != QModbusDevice::ConnectedState)
        {
            pollTimer->setInterval(ui->spinBoxInterval->text().toInt());
            pollTimer->start();

            ui->statusbar->showMessage(tr("启用循环发送"));
        }
        else
        {
            if (QMessageBox::Ok ==
                QMessageBox::question(this, tr("提示"),
                    QString(tr("串口 %1 并没有打开, 是否要打开串口 %2 ?"))
                    .arg(ui->comboBoxPort->currentText(), ui->comboBoxPort->currentText()),
                    QMessageBox::Ok, QMessageBox::Cancel))
            {
                on_actionConnect_triggered();
            }
            ui->checkBoxAuto->setChecked(false);
        }
    }
    else            //取消循环发送
    {
        pollTimer->stop();
        ui->statusbar->showMessage(tr("取消循环发送"));
    }
}



