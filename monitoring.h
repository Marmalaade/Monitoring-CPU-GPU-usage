#ifndef MONITORING_H
#define MONITORING_H

#include <QDialog>

namespace Ui {
class Monitoring;
}

class Monitoring : public QDialog
{
    Q_OBJECT

public:
    explicit Monitoring(QWidget *parent = nullptr);
    ~Monitoring();

private slots:

    void on_exitButtom_clicked();

    void on_getCPUusage_clicked();

    void on_getGPUusage_clicked();

private:
    Ui::Monitoring *ui;
};

#endif // MONITORING_H
