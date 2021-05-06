#include "Grid.h"


Grid::Grid(std::pair<int,int> size) : _size(size)
{
    for(int i=0;i<size.first;i++)
    {
        for(int j=0;j<size.second;j++)
        {
            _buttonGrid.at(i).at(j) = new QPushButton();
            _buttonGrid.at(i).at(j)->resize(15,15);
            _buttonGrid.at(i).at(j)->setContentsMargins(0,0,0,0);
            //tabButton.at(i).at(j)->setStyleSheet("border: none;");
            this->addWidget(_buttonGrid.at(i).at(j),i,j,1,1);
        }
    }


    std::pair<int,int> pos_food(30,40);


    std::vector<std::pair<int,int>> vectorPosObsacles={{19,25},{20,25},{22,25},{20,26}};

    for (std::pair<int,int>& pos: vectorPosObsacles){
    {
       _obstacles.at(pos.first).at(pos.second) = new Obstacle(pos);


    }
       // _foods.at(pos.first).at(pos.second) = new Food(pos) ;

    _pheromones.at(i).at(j);



    _ants.at(i).at(j)=;


    std::pair<int,int> pos_colony(25,50);
    _colonies.at(25).at(50) = new Colony(pos_colony,)

}
Grid::~Grid()
{

}





