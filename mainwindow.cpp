#include "mainwindow.h"
#include "myvideocapture.h"

MainWindowClass::MainWindowClass(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    mOpenCV_videoCapture = new MyVideoCapture(this);

    connect(mOpenCV_videoCapture, &MyVideoCapture::newPixmapCaptured, this, [&]() {
        ui->label_mainFrame->setPixmap(mOpenCV_videoCapture->pixmap().scaled(1000, 700));
        });
}

MainWindowClass::~MainWindowClass()
{
    delete ui;
    mOpenCV_videoCapture->terminate();
}

void MainWindowClass::on_pushButton_recording_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    mOpenCV_videoCapture->start(QThread::HighestPriority);
}