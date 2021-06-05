
#include "include_tools.h"

#ifndef ANTCOLONY_OBSTACLE_H
#define ANTCOLONY_OBSTACLE_H


class Obstacle {
public:
    Obstacle(std::pair<int, int> &coord);
    ~Obstacle();
    const std::pair<int, int> &getCoord() const;

    void setCoord(const std::pair<int, int> &coord);

private:
    std::pair<int,int> _coord;
};


#endif //ANTCOLONY_OBSTACLE_H
