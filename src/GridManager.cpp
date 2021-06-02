#include "GridManager.h"
#include "AntFighter.h"
#include <QTimer>



GridManager::GridManager(){}

GridManager::~GridManager()
{
    for (int i =0 ; i < gridSize.first;i++)
    {
        for (int j =0 ; j < gridSize.second;j++)
        {
            if(_foods.at(i).at(j)!=NULL)
                delete _foods.at(i).at(j);
            if(_obstacles.at(i).at(j)!=NULL)
                delete _obstacles.at(i).at(j);
            if(_buttonGrid.at(i).at(j)!=NULL)
                delete _buttonGrid.at(i).at(j);
            if(_pheromones.at(i).at(j)!=NULL)
                delete _pheromones.at(i).at(j);
        }
    }
    for (Colony* col: _colonies)
    {
       col->eraseALl();
       delete col;
    }

}

GridManager& GridManager::getInstance()
{
    static GridManager instance;
    return instance;
}

void GridManager::init(std::pair<int,int> size)
{
    _size=size;
    //initialize the size of every vector
    _buttonGrid.resize(size.first);
    _foods.resize(size.first);
    _obstacles.resize(size.first);
    _ants.resize(size.first);
    _pheromones.resize(size.first);

    for(int i=0;i<size.first;i++)
    {
        _buttonGrid.at(i).resize(size.second,NULL);
        _foods.at(i).resize(size.second,NULL);
        _obstacles.at(i).resize(size.second,NULL);
        _ants.at(i).resize(size.second,NULL);
        _pheromones.at(i).resize(size.second,NULL);

        for(int j=0;j<size.second;j++)
        {
            //create a button as a square
            _buttonGrid.at(i).at(j) = new QPushButton();
            _buttonGrid.at(i).at(j)->resize(15,15);
            _buttonGrid.at(i).at(j)->setContentsMargins(0,0,0,0);
            _buttonGrid.at(i).at(j)->setStyleSheet("border: none;");
            this->addWidget(_buttonGrid.at(i).at(j),i,j,1,1);
            std::pair<int,int> posPheromone(i,j);
            _pheromones.at(i).at(j) = new Pheromone(posPheromone);
        }
    }

    //Initialize the obstacles by default
    std::vector<std::pair<int,int>> vectorPosObsacles={{19,25},{20,25},{22,25},{20,26}};
    for (std::pair<int,int>& pos: vectorPosObsacles)
    {
       _obstacles.at(pos.first).at(pos.second) = new Obstacle(pos);
    }

    //Initialize the foods by default
    std::vector<std::pair<int,int>> vectorPosFood={{25,25},{26,25},{24,25},{20,27}};
    for (std::pair<int,int>& pos: vectorPosFood)
    {
       _foods.at(pos.first).at(pos.second) = new Food(pos) ;
    }

    _ants.at(1).at(1)=new AntFighter(std::make_pair(1,1));

    //Initialize the colony by default
    std::pair<int,int> posColony (size.first/2,size.second/2);
    Colony *firstColony = new Colony(posColony);
    _colonies.push_back(firstColony);
}


void GridManager::getInfoColony(Colony colony){}

std::vector<std::vector<QPushButton*>> GridManager::getButtonGrid()
{
    return _buttonGrid;
}

std::vector<std::vector<Pheromone*>> GridManager::getPheromones()
{
    return _pheromones;
}
std::vector<std::vector<Ant*>> GridManager::getAnts()
{
    return _ants;
}

std::vector<Colony*> GridManager::getColonies()
{
    return _colonies;
}
std::vector<std::vector<Food*>> GridManager::getFoods()
{
    return _foods;
}



Cell GridManager::getElementByCoord(std::pair<int,int> coord)
{
    //If out of bounds
    if(coord.first<0 || coord.second<0 || coord.first > gridSize.first || coord.second > gridSize.second) {
        return Cell::OOB;
    }else if( _ants.at(coord.first).at(coord.second)!=NULL ) {
        return Cell::ANT;
    } else if( _obstacles.at(coord.first).at(coord.second)!=NULL ){
        return Cell::OBSTACLE;
    }else if( _foods.at(coord.first).at(coord.second)!=NULL ) {
        return Cell::FOOD;
    }

    for (Colony* c: _colonies){
        if((c->getCoord().first == coord.first) && (c->getCoord().second == coord.second)) {
            return Cell::COLONY;
        }
    }

    return Cell::FREE;
}

void GridManager::getOutOfHere()
{
    //Make the ant leave the waiting queue where there is free space
    for (Colony* c: _colonies) {
        for(int i=-1 ;i<2 ;i++) {
            for(int j=-1 ;j<2 ;j++) {
                std::pair<int,int> newCoord (c->getCoord().first + i, c->getCoord().second +j );
                if(getElementByCoord(newCoord) == Cell::FREE && !c->getWaitArea().empty())
                {
                    c->getWaitArea().back()->moveTo(newCoord);
                    c->popBackWaitArea();
                }
            }
        }
    }
}

void GridManager::generateFoodObstacle(int type){

    std::pair<int,int> coordGenerated;
    coordGenerated.first = rand() % _size.first;
    coordGenerated.second = rand() % _size.second;

    if(getElementByCoord(coordGenerated) == Cell::FREE){
        if(type == 1){
            _foods.at(coordGenerated.first).at(coordGenerated.second) = new Food(coordGenerated) ;
        }else if(type == 2){
            _obstacles.at(coordGenerated.first).at(coordGenerated.second) = new Obstacle(coordGenerated);
        }
    }else{

    }
}


void GridManager::addAnts(Ant* ant,std::pair<int,int> coord){
    _ants.at(coord.first).at(coord.second) = ant;
}
void GridManager::removeAnt(std::pair<int,int> coord)
{
    _ants.at(coord.first).at(coord.second) = NULL;
}


void GridManager::display(const char* rcLink,std::pair<int,int> pos)
{
    QPixmap pixmap(rcLink);
    QIcon ButtonIcon(pixmap);
    _buttonGrid.at(pos.first).at(pos.second)->setIcon(ButtonIcon);
}

void GridManager::removeDisplay(std::pair<int,int> pos)
{
    _buttonGrid.at(pos.first).at(pos.second)->setIcon(QIcon());
}





