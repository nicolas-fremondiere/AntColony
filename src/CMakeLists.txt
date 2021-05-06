


find_package(Qt5Widgets REQUIRED)
target_link_libraries(AntColony Qt5::Widgets)

add_executable(AntColony # name of the executable on Windows will be example.exe
        main.cpp
        AntWorker.cpp
        AntWorker.h
        Ant.h
        AntFighter.cpp
        AntFighter.h
        AntEgg.cpp
        AntEgg.h
        AntLarva.cpp
        AntLarva.h
        AntQueen.cpp
        AntQueen.h
        Pheromone.h
        Pheromone.cpp
        Grid.cpp
        Grid.h
        Obstacle.cpp
        Obstacle.h
        Colony.cpp
        Colony.h
        Food.cpp
        Food.h
        include_tools.h
        )


target_link_libraries(AntColony ${wxWidgets_LIBRARIES})