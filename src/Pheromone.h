
#include "include_tools.h"
#ifndef ANTCOLONY_PHEROMONE_H
#define ANTCOLONY_PHEROMONE_H


class Pheromone {
public:
    Pheromone(std::pair<int, int> &coord, float concentration=0.0);

    const std::pair<int, int> &getCoord() const;

    void setCoord(const std::pair<int, int> &coord);

    float getConcentration() const;

    void setConcentration(float concentration);
    void updateDisplay();

private:

    std::pair<int,int> _coord;
    bool _foodAhead;
    float _concentration;
    int _colonyId;
};


#endif //ANTCOLONY_PHEROMONE_H
