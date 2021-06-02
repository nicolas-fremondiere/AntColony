QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 static

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CellButton.cpp \
    EventLoop.cpp \
    main.cpp \
    mainwindow.cpp \
    src/AntEgg.cpp \
    src/AntFighter.cpp \
    src/AntLarva.cpp \
    src/AntQueen.cpp \
    src/AntWorker.cpp \
    src/Colony.cpp \
    src/Food.cpp \
    src/GridManager.cpp \
    src/Obstacle.cpp \
    src/Pheromone.cpp

HEADERS += \
    CellButton.h \
    EventLoop.h \
    mainwindow.h \
    src/Ant.h \
    src/AntEgg.h \
    src/AntFighter.h \
    src/AntLarva.h \
    src/AntQueen.h \
    src/AntWorker.h \
    src/Colony.h \
    src/Food.h \
    src/GridManager.h \
    src/Obstacle.h \
    src/Pheromone.h \
    src/include_tools.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    AntColony_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ant.qrc

DISTFILES += \
    src/CMakeLists.txt
