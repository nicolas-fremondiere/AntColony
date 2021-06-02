#ifndef EVENTLOOP_H
#define EVENTLOOP_H

#include <QObject>
#include <QWidget>
#include <QKeyEvent>

class EventLoop : public QWidget
{
    Q_OBJECT
public:
    EventLoop(QWidget *parent =nullptr);

protected:
    virtual void update();
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // EVENTLOOP_H
