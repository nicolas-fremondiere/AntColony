
#include "include_tools.h"
#include "Colony.h"
#include "Food.h"
#include "Obstacle.h"
#include "Pheromone.h"
#include <QGridLayout>
#include <QPushButton>

#ifndef ANTCOLONY_GRID_H
#define ANTCOLONY_GRID_H

const std::pair<int,int> gridSize(50,100);


class GridManager :public QGridLayout{
public:
    GridManager();
    ~GridManager();
    static GridManager& getInstance();
    void init(std::pair<int,int> size);
    void display(const char* rcLink,std::pair<int,int> pos);
    void getInfoColony(Colony colony);

private:
    std::pair<int,int> _size;

    std::vector<std::vector<Food*>> _foods;
    std::vector<std::vector<Obstacle*>> _obstacles;
    std::vector<std::vector<Pheromone*>> _pheromones;
    std::vector<std::vector<Ant*>> _ants;
    std::vector<Colony*> _colonies;
    std::vector<std::vector<QPushButton*>> _buttonGrid;
};


#endif //ANTCOLONY_GRID_H
