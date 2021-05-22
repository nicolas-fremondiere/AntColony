#ifndef EVENTLOOP_H
#define EVENTLOOP_H

#include <QObject>
#include <QWidget>

class EventLoop : public QWidget
{
    Q_OBJECT
public:
    EventLoop(QWidget *parent =nullptr);

protected:
    virtual void update();
};

#endif // EVENTLOOP_H
