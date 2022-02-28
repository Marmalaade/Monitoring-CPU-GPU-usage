#include "cpuusage.h"
#include "QGraphicsDropShadowEffect"

CPUusage :: CPUusage() : prevIdleTime(0), prevTotalTime(0)
    {
        connect(this, &QProgressDialog::finished, &QApplication::quit);
        setLabelText(tr("CPU utilization"));
        setWindowTitle("CPU");
        this->setStyleSheet("background-color: rgb(180, 180, 180)");
        setFixedSize(300, 150);
        setCancelButtonText(tr("Refresh"));
        startTimer(500);
    }


