cmake_minimum_required(VERSION 3.19)
project(AntColony)

set(CMAKE_CXX_STANDARD 17)

add_executable(AntColony main.cpp include/Ant.h include/AntWorker.h include/AntFighter.h include/AntEgg.h include/AntLarva.h src/Pheromone.cpp include/Pheromone.h src/Grid.cpp include/Grid.h src/AntQueen.cpp include/AntQueen.h src/Food.cpp include/Food.h src/Obstacle.cpp include/Obstacle.h src/AntEgg.cpp src/AntFighter.cpp src/AntLarva.cpp src/AntWorker.cpp src/Colony.cpp include/Colony.h include/include_tools.h)