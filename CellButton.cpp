#include "CellButton.h"
#include "src/GridManager.h"
#include <QString>
#include "src/include_tools.h"

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

        int amountOfEgg = myColony->countAnt(TYPE_ANT::EGG);
        int amountOfWorker = myColony->countAnt(TYPE_ANT::WORKER);
        int amountOfLarva = myColony->countAnt(TYPE_ANT::LARVA);
        int amountOfFighter = myColony->countAnt(TYPE_ANT::FIGHTER);
        int amountOfQueen = myColony->countAnt(TYPE_ANT::QUEEN);
        QString info = QString("Egg : %1\nLarva : %2\nWorker : %3\nFighter : %4\nQueen : %5").arg(amountOfEgg).arg(amountOfLarva).arg(amountOfWorker).arg(amountOfFighter).arg(amountOfQueen);


        setToolTip(info);
    }
}
