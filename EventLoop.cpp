#include <EventLoop.h>
#include <QTimer>
#include <QtDebug>
#include <src/GridManager.h>
#include <src/AntQueen.h>
#include <src/AntEgg.h>
#include <src/AntLarva.h>
#include <src/AntWorker.h>
#include <src/AntFighter.h>


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

    //random occurrence of foods (= 1) and obstacles (= 2)
    int occurence = rand() % 100;
    if(occurence < 20){
        instanceGridManager.generateFoodObstacle(1);
    }else if(occurence > 20 && occurence < 25){
        instanceGridManager.generateFoodObstacle(2);
    }

    //creation new ant
    for(Colony* c : instanceGridManager.getColonies()){
        for(Ant* ant : c->getAnts()){
            if(ant->getType() == QUEEN){
                AntQueen* queen = dynamic_cast<AntQueen*>(ant);
                queen->setTimeSinceEggLaying(queen->getTimeSinceEggLaying() + 1);
                if(queen->getTimeSinceEggLaying() >= 5){
                    queen->setTimeSinceEggLaying(0);
                    // Initialization of an ant egg in the colony
                    AntEgg *newEgg = new AntEgg(c->getCoord());
                    newEgg->setColony(c);
                    c->addAnt(newEgg);
                }
            }
        }
    }

    //management of the age and the hunger of ants
    for(Colony* c : instanceGridManager.getColonies()){
        for(Ant* ant : c->getAnts()){
            ant->addAge();
            ant->hungerDamage();
            if(ant->getType() == EGG && ant->getAge() > 10){

                // Evolution of egg to larva
                AntLarva* newLarva = new AntLarva(c->getCoord());
                newLarva->setColony(c);
                c->addAnt(newLarva);
                // deletion of the egg
                c->deleteAnt(ant);
                delete ant;

            }else if(ant->getType() == LARVA && ant->getAge() > 20){

                // Evolution of larva to worker
                AntWorker* newWorker = new AntWorker(c->getCoord());
                newWorker->setColony(c);
                c->addAnt(newWorker);
                // deletion of the larva
                c->deleteAnt(ant);
                delete ant;

            }else if(ant->getType() == WORKER && ant->getAge() > 30){

                // Evolution of worker to fighter
                AntFighter* newFighter = new AntFighter(c->getCoord());
                newFighter->setColony(c);
                c->addAnt(newFighter);
                // deletion of the worker
                c->deleteAnt(ant);
                delete ant;

            }else if(ant->getType() == FIGHTER && ant->getAge() > 60){

                // the death of a fighter
                GridManager::getInstance().removeDisplay(ant->getCoord());
                GridManager::getInstance().removeAnt(ant->getCoord());
                c->deleteAnt(ant);
                delete ant;

            }
        }
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
