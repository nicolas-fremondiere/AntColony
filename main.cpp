#include <QtWidgets>
#include <QGridLayout>
#include <QApplication>
#include <QPushButton>
#include <vector>
#include <QScreen>
#include <src/GridManager.h>




int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    GridManager &grid = GridManager::getInstance();
    grid.init(gridSize);

    // Create a widget
    QWidget *w = new QWidget();

    // Set the grid layout as a main layout
    w->setLayout(&grid);


    grid.setSpacing(0);
    // Window title
    w->setWindowTitle("Grid Layouts");


    //get screen size
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();


    w->setFixedSize(QSize(width,height-70));

    w->setStyleSheet("background-color: rgb(255,255,255);");

    // Display
    w->show();

    for (int i=0;i<10;i++)
    {
        GridManager::getInstance().display(ANT_IMG,std::make_pair(20,i));
    }


    // Event loop
    return app.exec();
}
