#include <EventLoop.h>
#include <QTimer>
#include <QtDebug>
#include <src/GridManager.h>


void EventLoop::update()
{
    qDebug() << "update() called";
    int i = rand()%50;
    int j = rand()%100;

    GridManager::getInstance().display(HOUSE_IMG,std::make_pair(i,j));
}

EventLoop::EventLoop(QWidget *parent)
    : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&EventLoop::update));
    timer->start(500);
}
