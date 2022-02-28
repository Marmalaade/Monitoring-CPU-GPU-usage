#include "monitoring.h"
#include "ui_monitoring.h"
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QLabel>
#include <QComboBox>
#include "cpuusage.h"
#include "mainwindow.h"
#include "gpuusage.h"
Monitoring::Monitoring(QWidget *parent) :

    QDialog(parent),
    ui(new Ui::Monitoring)
{
    ui->setupUi(this);
    this->setWindowTitle("Monitoring");

}

Monitoring::~Monitoring()
{

}

void Monitoring::on_exitButtom_clicked()
{
   hide();
   MainWindow *main=new MainWindow();
   main->show();
}




void Monitoring::on_getCPUusage_clicked()
{
    CPUusage *cpu=new CPUusage();
    cpu->show();
}

void Monitoring::on_getGPUusage_clicked()
{
    GPUusage *gpu=new GPUusage();
    gpu->getMama();
    gpu->show();
}
