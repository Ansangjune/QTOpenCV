#pragma once
#include <QThread>
#include <QPixmap>
#include <QImage>
#include <opencv2/opencv.hpp>


class MyVideoCapture : public QThread
{
    Q_OBJECT
public:
    MyVideoCapture(QObject* parent = nullptr);

    QPixmap pixmap() const
    {
        return mPixmap;
    }
    bool stopped;
signals:
    void newPixmapCaptured();

protected:
    void run() override;

private:
    QPixmap mPixmap;
    cv::Mat mFrame;
    cv::VideoCapture cap;

    QImage cvMatToQImage(const cv::Mat& inMat);
    QPixmap cvMatToQPixmap(const cv::Mat& inMat);

};