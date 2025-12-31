#ifndef SCREENCAPTUREENCODER_H
#define SCREENCAPTUREENCODER_H

#include <QObject>
#include <QTimer>
#include <QScreen>
#include <QGuiApplication>
#include <QImage>
#include <QPixmap>
#include <QDebug>

// FFmpeg includes
extern "C" {
#include <libavcodec/avcodec.h>
#include <libavutil/imgutils.h>
#include <libavutil/opt.h>
#include <libswscale/swscale.h>
}

class ScreenCaptureEncoder : public QObject
{
    Q_OBJECT
public:
    explicit ScreenCaptureEncoder(QObject* parent = nullptr);
    ~ScreenCaptureEncoder();

    void startCapture();
    // 停止捕获
    void stopCapture();

signals:
    // 当编码出数据包后发出信号，由外部处理发送逻辑
    void encodedPacketReady(const QByteArray& packet);

private slots:
    void captureAndEncode();

private:
    void reinitializeEncoder(int newWidth, int newHeight);

    QImage grabDXG();
    void initDXGIManager();
    void unitDXGIManager();

    QSize getFixedSize();

    // DXG屏幕捕获
    bool m_bInitDXGI = false;
    unsigned char* m_pBuff = Q_NULLPTR;
    int m_iBuffSize = 0;
    int m_iDeskWidth;
    int m_iDeskHeight;
    QImage m_image;
    int m_iFrame = 0;

private:
    // FFmpeg相关成员
    const AVCodec* codec;
    AVCodecContext* codecCtx;
    AVFrame* frame;
    struct SwsContext* swsCtx;
    int frameCounter;
    QTimer* timer;
};

#endif // SCREENCAPTUREENCODER_H
