#include "CellButton.h"
#include "src/GridManager.h"
#include <QString>
#include "src/include_tools.h"
#include <QMouseEvent>
CellButton::CellButton(std::pair<int,int> coord) : _coord(coord){

}
void CellButton::enterEvent(QEnterEvent *event) {

    if(GridManager::getInstance().getElementByCoord(_coord) == Cell::COLONY)
    {
        Colony* myColony=NULL;
        for (Colony* c: GridManager::getInstance().getColonies()){
            if(c->getCoord() == _coord) {
                myColony=c;
                break;
            }
        }
        if(myColony == NULL)
            return;
        int amountOfFood = myColony->getFoodStorage();
        int amountOfEgg = myColony->countAnt(TYPE_ANT::EGG);
        int amountOfWorker = myColony->countAnt(TYPE_ANT::WORKER);
        int amountOfLarva = myColony->countAnt(TYPE_ANT::LARVA);
        int amountOfFighter = myColony->countAnt(TYPE_ANT::FIGHTER);
        int amountOfQueen = myColony->countAnt(TYPE_ANT::QUEEN);
        QString info = QString("Egg : %1\nLarva : %2\nWorker : %3\nFighter : %4\nQueen : %5\nFood : %6").arg(amountOfEgg).arg(amountOfLarva).arg(amountOfWorker).arg(amountOfFighter).arg(amountOfQueen).arg(amountOfFood);

        setToolTip(info);
    }
    else if(GridManager::getInstance().getElementByCoord(_coord) == Cell::FOOD)
    {
        int amountOfFood =GridManager::getInstance().getFoods().at(_coord.first).at(_coord.second)->getCurrentQuantity();
        QString info = QString("Food : %1").arg(amountOfFood);
        setToolTip(info);

    }

}


void CellButton::mousePressEvent(QMouseEvent *event){

    switch (event->button()) {
        case Qt::LeftButton:
            if(GridManager::getInstance().getElementByCoord(_coord) == Cell::FREE)
            {
                GridManager::getInstance().addFood(_coord);
            }
            else if (GridManager::getInstance().getElementByCoord(_coord) == Cell::FOOD)
            {
                GridManager::getInstance().deleteFood(_coord);
            }
        break;
        case Qt::RightButton:
            if(GridManager::getInstance().getElementByCoord(_coord) == Cell::FREE)
            {
                GridManager::getInstance().addObstacles(_coord);
            }
            else if (GridManager::getInstance().getElementByCoord(_coord) == Cell::OBSTACLE)
            {
                GridManager::getInstance().deleteObstacles(_coord);
            }
        break;
        case Qt::MiddleButton:
            if(GridManager::getInstance().getElementByCoord(_coord) == Cell::FREE)
            {
                GridManager::getInstance().addColonies(_coord);
            }

        break;
        default:
        break;
    }


}
