#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QSerialPort>
//#include <QSerialPortInfo>
#include <QJsonDocument>
#include <QJsonObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

 //   QSerialPort serial;


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void dadosRecebidos();

    bool dadosRecebidos_1();

    void on_btn_conectar_clicked();

    void on_btn_desconectar_clicked();

    void on_btn_desligasist_clicked();

    void on_btn_ligarValvula();

    void on_btn_desligarValvula();

//    void on_cBox_serial_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

/*
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "comserial.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QMainWindow *parent = 0);
    ~MainWindow();


private slots:
    void on_pbCloseSerial_clicked();
    void on_pbOpenSerial_clicked();
    void on_pbSendCmd_clicked();

    void WriteData(const QByteArray data);
    void ReadData();



private:
    Ui::Widget *ui;

    QSerialPort *devserial;
    comserial *procSerial;

    void CarregarInfoDispSerial(void);
};

#endif // WIDGET_H
*/
