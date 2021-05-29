#include <EventLoop.h>
#include <QTimer>
#include <QtDebug>
#include <src/GridManager.h>


void EventLoop::update()
{
    qDebug() << "update() called";

    GridManager& instanceGridManager = GridManager::getInstance();

    instanceGridManager.getOutOfHere();

    //update the color for the pheromone
    for(int i=0; i <gridSize.first;i++) {
        for(int j=0;j < gridSize.second;j++) {
            instanceGridManager.getPheromones().at(i).at(j)->updateDisplay();
        }
    }

}

EventLoop::EventLoop(QWidget *parent)
    : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&EventLoop::update));
    timer->start(1000);
}
