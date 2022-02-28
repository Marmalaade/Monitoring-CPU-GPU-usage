#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QLabel>
#include "cpuusage.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{    ui->setupUi(this);
     QPixmap bkgnd("/imgs/imgs/background.jpg)");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    hide();
    monitoring =new Monitoring(this);
    monitoring->show();

}


void MainWindow::on_infoButton_clicked()
{
     QMessageBox::information(this,"Information about app","Данное приложение позволяет следить за загруженностью графического и центрального процессора.");
}





void MainWindow::on_mainExitbutton_clicked()
{
            QMessageBox::StandardButton reaplyExit=QMessageBox::question(this,"Exit confirmation","Вы действительно хотите выйти?",
                    QMessageBox::Yes | QMessageBox::No);
            if(reaplyExit==QMessageBox::Yes){
                QApplication::quit();
            }
            else {
                qDebug()<<"Возврат в приложение...";

            }
}
