#include "gpuusage.h"
#include "QGraphicsDropShadowEffect"

GPUusage :: GPUusage()
    {
        connect(this, &QProgressDialog::finished, &QApplication::quit);
        setLabelText(tr("GPU utilization"));
        setWindowTitle("GPU");
        this->setStyleSheet("background-color: rgb(180, 180, 180)");
        setFixedSize(300, 150);
        setCancelButtonText(tr("Refresh"));
        startTimer(500);
    }

