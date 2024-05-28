#include "dialog.h"
#include "ui_dialog.h"

dialog::dialog(QWidget *parent)
    : QDialog{parent},
    ui(new Ui::dialog)
{
    ui->setupUi(this);

    m_mainwindow = (MainWindow*)parentWidget();
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(connectconfig()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(connectclose()));

    InitialSetting();

}

dialog::~dialog()
{
    delete ui;
}

void dialog::InitialSetting()
{
    //填充串口号组合框
    SearchSerialPorts();

    //填充串口波特率
    QStringList baud={"4800","9600","14400","19200","28800","38400","56000","57600","115200","128000","230400","256000"};
    ui->comboBoxBaud->addItems(baud);

    //填充串口数据位
    ui->comboBoxData->addItem("8 bits");

    //填充串口校验位
    ui->comboBoxParity->addItem("无校验");
    ui->comboBoxParity->addItem("奇校验");
    ui->comboBoxParity->addItem("偶校验");

    //填充串口停止位
    ui->comboBoxStop->addItem("1位");
    ui->comboBoxStop->addItem("1.5位");
    ui->comboBoxStop->addItem("2位");

    ui->comboBoxHand->addItem("yes");
    ui->comboBoxHand->setCurrentIndex(0);

}

//搜索串口
void dialog::SearchSerialPorts()
{
    ui->comboBoxPort->clear();
    if(QSerialPortInfo::availablePorts().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("无可用串口设备"),QMessageBox::Ok);
        return;
    }

    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        ui->comboBoxPort->addItem(info.portName());
    }
}

void dialog::connectconfig(){

    if (!m_mainwindow->modbusDevice)
        return;

    m_mainwindow->modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,ui->comboBoxPort->currentText());
    m_mainwindow->modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,ui->comboBoxBaud->currentText().toInt());

    m_mainwindow->ui->comboBoxPort->setCurrentIndex(ui->comboBoxPort->currentIndex());
    m_mainwindow->ui->comboBoxBaud->setCurrentIndex(ui->comboBoxBaud->currentIndex());
    m_mainwindow->ui->comboBoxData->setCurrentIndex(ui->comboBoxData->currentIndex());
    m_mainwindow->ui->comboBoxStop->setCurrentIndex(ui->comboBoxStop->currentIndex());
    m_mainwindow->ui->comboBoxParity->setCurrentIndex(ui->comboBoxParity->currentIndex());
    switch(ui->comboBoxParity->currentIndex())                   //设置奇偶校验
    {
        case 0: m_mainwindow->modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,QSerialPort::NoParity);break;
        default: break;
    }

    switch(ui->comboBoxData->currentIndex())                   //设置数据位数
    {
    case 0:m_mainwindow->modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,QSerialPort::Data8);break;
        default: break;
    }

    switch(ui->comboBoxStop->currentIndex())                     //设置停止位
    {
        case 1: m_mainwindow->modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::OneStop);break;
        case 2: m_mainwindow->modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::TwoStop);break;
        default: break;
    }

    m_mainwindow->modbusDevice->setTimeout(1000);
    m_mainwindow->modbusDevice->setNumberOfRetries(3);
    if (m_mainwindow->modbusDevice->connectDevice())
    {
        m_mainwindow->ui->actionConnect->setEnabled(false);
        m_mainwindow->ui->actionDisconnect->setEnabled(true);
        m_mainwindow->ui->actionRefresh->setEnabled(false);
    }
    else    //打开失败提示
    {

        QMessageBox::information(this,tr("错误"),tr("连接从站失败！"),QMessageBox::Ok);
    }
}


void dialog::connectclose(){

    QMessageBox::information(this,tr("错误"),tr("连接从站失败！"),QMessageBox::Ok);
    this->close();
    m_mainwindow->close();
}

void dialog::on_pushButton_camera_clicked(){

//    QFileDialog * fileDialog = new QFileDialog(this);
//    //fileDialog->setDirectory("E:\\");
//    fileDialog->setWindowTitle(QString::fromLocal8Bit("选择相机数据存储路径"));
//    fileDialog->setNameFilter(QString::fromLocal8Bit("All C++ files (*.cpp *.cc *.C *.cxx *.c++ *.txt *.png)"));
//    if ( fileDialog->exec() == QDialog::DialogCode::Accepted )
//    {
//        camera_path = fileDialog->selectedFiles()[0];
//        QMessageBox::information(nullptr, QString::fromLocal8Bit("选择的文件"), QString::fromLocal8Bit("文件路径: ") + path);
//    }
//    else
//    {
//        QMessageBox::information(nullptr, QString::fromLocal8Bit("选择的文件"), QString::fromLocal8Bit("没有选择文件"));
//    }
    camera_path = QFileDialog::getExistingDirectory(this, tr("选择相机图像保存路径"), "C:\\");
    ui->lineEdit_camera->setText(camera_path);
}

void dialog::on_pushButton_command_clicked(){

    command_path = QFileDialog::getExistingDirectory(this, tr("选择指令保存路径"), "C:\\");
    ui->lineEdit_command->setText(command_path);
}

void dialog::on_pushButton_lineccd_clicked(){

    lineccd_path = QFileDialog::getExistingDirectory(this, tr("选择LineCCD保存保存路径"), "C:\\");
    ui->lineEdit_lineccd->setText(lineccd_path);

}
