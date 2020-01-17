#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    for(auto& item : QSerialPortInfo::availablePorts()){
        ui->box_serial->addItem(item.portName());
    }

    for(auto& item : QSerialPortInfo::standardBaudRates()){
        ui->box_velocidade->addItem(QString::number(item));
        serial.setBaudRate(115200);
    }

    connect(&serial,
            SIGNAL(readyRead()),
            this,
            SLOT(dadosRecebidos()));

    for(auto& item : QSerialPortInfo::availablePorts())
        ui->box_serial->addItem(item.portName());

    for(auto& item : QSerialPortInfo::standardBaudRates())
        ui->box_velocidade->addItem(QString::number(item) );

    connect(&serial,
            SIGNAL(readyRead()),
            this,
            SLOT(dadosRecebidos()));
   }

MainWindow::~MainWindow()
{
    serial.close();
    delete ui;
}

void MainWindow::dadosRecebidos()
{
    auto data = serial.readAll();
    auto dados = QJsonDocument::fromJson(data).object().toVariantMap();

    if(dados.contains("LUMINOSIDADE")){
        Luminosidade = dados["LUMINOSIDADE"].toString();
        ui->lbl_LDR->setText(Luminosidade);
        }

    if(dados.contains("UMIDADE_SOLO")){
        Umidade_Solo = dados["UMIDADE_SOLO"].toString();
        ui->lbl_umidade_solo->setText(Umidade_Solo);
        }

    if(dados.contains("TEMPERATURA_AR")){
        Temperatura_ar = dados["TEMPERATURA_AR"].toString();
        ui->lbl_temperatura_ar->setText(Temperatura_ar);
        }

    if(dados.contains("UMIDADE_AR")){
        Umidade_ar = dados["UMIDADE_AR"].toString();
        ui->lbl_umidade_ar->setText(Umidade_ar);
        }
}

void MainWindow::on_btnPlug_clicked()
{
    plugStatus = !plugStatus;

    if(plugStatus){
        serial.setPortName(ui->box_serial->currentText());
        serial.setBaudRate(115200);

        if(serial.open(QIODevice::ReadWrite)){
            ui->status_conexao->setText("Status: Conectado");
            ui->btnPlug ->setText("Desconectar");
        }
    }
}


void MainWindow::on_btnModo_Activated(const QString &arg1)
{
    if(ui->combo_Sistema->setCurrentText("Automatico")) {
        (arg1 == "Modo automatico") serial.write("{\"MODO\": 1}"), ui->labeltxt->setText(text[1]);

    }else if(ui->combo_Sistema->setCurrentText("Manual")){
        (arg1 == "Modo manual") serial.write("{\"MODO\": 2}"), ui->labeltxt->setText(text[2]);

    }else{
        ();
    }
}


/*void MainWindow::on_btn_desligasist_clicked()
{
  //  serial.write("{\"T_OFF\": 0}\n");
 //   ui->lbl_lcd->setText("Em funcionamento...");
    ui->label->setEnabled(0);
}
*/

