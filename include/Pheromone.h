
#include "include_tools.h"
#ifndef ANTCOLONY_PHEROMONE_H
#define ANTCOLONY_PHEROMONE_H


class Pheromone {
public:
    Pheromone(const std::pair<int, int> &coord, bool foodAhead, float concentration, int colonyId);

    const std::pair<int, int> &getCoord() const;

    void setCoord(const std::pair<int, int> &coord);

    bool isFoodAhead() const;

    void setFoodAhead(bool foodAhead);

    float getConcentration() const;

    void setConcentration(float concentration);

    int getColonyId() const;

    void setColonyId(int colonyId);

private:

    std::pair<int,int> _coord;
    bool _foodAhead;
    float _concentration;
    int _colonyId;
};


#endif //ANTCOLONY_PHEROMONE_H
