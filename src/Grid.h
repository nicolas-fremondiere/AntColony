
#include "include_tools.h"
#include "Colony.h"
#include "Food.h"
#include "Obstacle.h"
#include "Pheromone.h"

#ifndef ANTCOLONY_GRID_H
#define ANTCOLONY_GRID_H


class Grid {
public:
    Grid(std::pair<int,int> size);
    ~Grid();

private:
    std::pair<int,int> _size;

    std::vector<std::vector<Food*>> _foods;
    std::vector<std::vector<Obstacle*>> _obstacles;
    std::vector<std::vector<Pheromone>> _pheromones;
    std::vector<std::vector<Ant*>> _ants;
    std::vector<Colony*> _colonies;

};


#endif //ANTCOLONY_GRID_H
