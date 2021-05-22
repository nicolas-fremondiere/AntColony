#include "GridManager.h"
#include "AntFighter.h"
#include <QTimer>



GridManager::GridManager(){}

GridManager::~GridManager(){}

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
        _buttonGrid.at(i).resize(size.second);
        _foods.at(i).resize(size.second);
        _obstacles.at(i).resize(size.second);
        _ants.at(i).resize(size.second);
        _pheromones.at(i).resize(size.second);

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

    //std::pair<int,int> posColony(0,1);

    //_colonies.at(0) = new Colony(posColony);


}

std::vector<std::vector<QPushButton*>> GridManager::getButtonGrid()
{
    return _buttonGrid;
}

std::vector<std::vector<Pheromone*>> GridManager::getPheromones()
{
    return _pheromones;
}

void GridManager::display(const char* rcLink,std::pair<int,int> pos)
{
    QPixmap pixmap(rcLink);
    QIcon ButtonIcon(pixmap);
    _buttonGrid.at(pos.first).at(pos.second)->setIcon(ButtonIcon);
}




