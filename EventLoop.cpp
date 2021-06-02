#include <EventLoop.h>
#include <QTimer>
#include <QtDebug>
#include <src/GridManager.h>


void EventLoop::update()
{
    GridManager& instanceGridManager = GridManager::getInstance();

    //The ants leave the nest!
    instanceGridManager.getOutOfHere();

    for(Colony* c : instanceGridManager.getColonies() ) {

        // Order the colonies to order its ants to do something
        c->behaveAll();
    }

    //update the color for the pheromone
    for(int i=0; i <gridSize.first;i++) {
        for(int j=0;j < gridSize.second;j++) {
            instanceGridManager.getPheromones().at(i).at(j)->decayConcentration(2);
            instanceGridManager.getPheromones().at(i).at(j)->updateDisplay();
        }
    }

    //random occurrence of foods (= 1) and obstacles (=2)
    int occurence = rand() % 100;
    if(occurence < 20){
        instanceGridManager.generateFoodObstacle(1);
    }else if(occurence > 20 && occurence < 25){
        instanceGridManager.generateFoodObstacle(2);
    }
}

void EventLoop::keyPressEvent(QKeyEvent *event)
{
    std::cout<<"WTF"<<std::endl;
    qDebug()<<"MDR lami";

    if( event->key() == Qt::Key_Space )
    {
        qDebug()<<"Salut lami";
    }
}





EventLoop::EventLoop(QWidget *parent)
    : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&EventLoop::update));
    timer->start(200);
}
