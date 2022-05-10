#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowClass; }
QT_END_NAMESPACE

class MyVideoCapture;

class MainWindowClass : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowClass(QWidget* parent = nullptr);
    ~MainWindowClass();

private slots:
    void on_pushButton_recording_clicked();

private:
    Ui::MainWindowClass* ui;
    MyVideoCapture* mOpenCV_videoCapture;
};
