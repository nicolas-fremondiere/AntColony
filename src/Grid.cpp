//
// Created by nfrem on 29/04/2021.
//

#include "../include/Grid.h"

Grid::Grid(const std::pair<int, int> &size, const std::vector<std::vector<Food>> &foods,
           const std::vector<std::vector<Obstacle>> &obstacles, const std::vector<std::vector<Pheromone>> &pheromones,
           const std::vector<std::vector<Ant>> &ants, const std::vector<Colony> &colonies) : _size(size), _foods(foods),
                                                                                             _obstacles(obstacles),
                                                                                             _pheromones(pheromones),
                                                                                             _ants(ants),
                                                                                             _colonies(colonies)
{

}
