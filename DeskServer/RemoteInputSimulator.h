#pragma once

#include <QObject>
#include <Windows.h>
#include <QThread>

#include "rendezvous.pb.h"

#include "DeskDefine.h"

class RemoteInputSimulator : public QObject
{
    Q_OBJECT

public:
    explicit RemoteInputSimulator(QObject* parent = nullptr);

public slots:
    void handleMouseEvent(int x, int y, int mask, int value);
    void handleTouchEvent(int timestamp, QList<DeskTouchPoint> points);
    void handleKeyboardEvent(int key, bool pressed);

private:
    QThread* m_workerThread = nullptr;
};
