#pragma once

#ifndef DESKDEFINE_H
#define DESKDEFINE_H

#include <QObject>
#include <QList>

enum MouseMask
{
    MouseMove        = 0x01, // 鼠标移动
    MouseLeftDown    = 0x02, // 鼠标左键按下
    MouseLeftUp      = 0x04, // 鼠标左键释放
    MouseDoubleClick = 0x08, // 鼠标左键双击
    MouseRightClick  = 0x10, // 鼠标右键单击
    MouseMiddleClick = 0x20, // 鼠标中键单击
    MouseWheel       = 0x40  // 鼠标滚轮
};

enum DeskTouchPhase
{
    TOUCH_BEGIN  = 0,
    TOUCH_MOVE   = 1,
    TOUCH_END    = 2,
    TOUCH_CANCEL = 3
};

struct DeskTouchPoint
{
    int id = 1;
    int x = 2;
    int y = 3;
    DeskTouchPhase phase;
    float pressure;
    float size = 5.0;
};
Q_DECLARE_METATYPE(DeskTouchPoint)

#include <QDebug>
// 重定义
inline QDebug operator << (QDebug debug, const DeskTouchPoint &pt)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << "DeskTouchPoint(id=" << pt.id
                    << ", x=" << pt.x
                    << ", y=" << pt.y
                    << ", phase=" << pt.phase
                    << ", pressure=" << pt.pressure
                    << ", size=" << pt.size
                    << ")";
    return debug;
}

struct DeskTouchEvent
{
    int timestamp;
    QList<DeskTouchPoint> points;
};
Q_DECLARE_METATYPE(DeskTouchEvent)

#endif // DESKDEFINE_H
