
#include "include_tools.h"
#include "Colony.h"
#include "Food.h"
#include "Obstacle.h"
#include "Pheromone.h"
#include <QGridLayout>
#include "CellButton.h"

#ifndef ANTCOLONY_GRID_H
#define ANTCOLONY_GRID_H

const std::pair<int,int> gridSize(50,100);
const double quarterDistance = sqrt(pow((-1 - gridSize.first ),2) + pow((-1 - gridSize.second),2)) /6;

enum Cell{
    OOB,
    FREE,
    COLONY,
    ANT,
    FOOD,
    OBSTACLE
};


class GridManager :public QGridLayout{
public:
    GridManager();
    ~GridManager();
    static GridManager& getInstance();
    std::vector<std::vector<CellButton*>> getButtonGrid();
    std::vector<std::vector<Pheromone*>> getPheromones();
    std::vector<std::vector<Ant*>> getAnts();
    std::vector<std::vector<Food*>> getFoods();
    std::vector<std::vector<Obstacle*>>  getObstacles();
    std::vector<Colony*> getColonies();

    template <typename T> T* getElement(std::vector<std::vector<T*>>tab, std::pair<int,int> coord){return tab.at(coord.first).at(coord.second);}


    void init(std::pair<int,int> size);
    void display(const char* rcLink,std::pair<int,int> pos);
    void removeDisplay(std::pair<int,int> pos);

    //Determine the type of object on a cell
    Cell getElementByCoord(std::pair<int,int> coord);
    //Make an ant leave the nest
    void getOutOfHere();
    //random algorithm to generate food and obstacles
    void generateFoodObstacle(int type);

    //Manage the addition or deletion of colonies,ants,obstacles or foods
    void addAnts(Ant* ant,std::pair<int,int> coord);
    void removeAnt(std::pair<int,int> coord);
    void addColonies(std::pair<int,int> coord);
    void addObstacles(std::pair<int,int> coord);
    void addFood(std::pair<int,int> coord);
    void deleteObstacles(std::pair<int,int> coord);
    void deleteFood(std::pair<int,int> coord);
    //measure the distance between 2 coordinate
    double getDistance(std::pair<int,int> coord1,std::pair<int,int> coord2);
private:
    std::pair<int,int> _size;

    std::vector<std::vector<Food*>> _foods;
    std::vector<std::vector<Obstacle*>> _obstacles;
    std::vector<std::vector<Pheromone*>> _pheromones;
    std::vector<std::vector<Ant*>> _ants;
    std::vector<Colony*> _colonies;
    std::vector<std::vector<CellButton*>> _buttonGrid;

};


#endif //ANTCOLONY_GRID_H
