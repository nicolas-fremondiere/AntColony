#include <QtWidgets>
#include <QGridLayout>
#include <QApplication>
#include <QPushButton>
#include <vector>
#include <QScreen>
#include <src/Grid.h>


#define M 50
#define N 100

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    std::pair<int,int> size(N,M);

    Grid *grid = new Grid(size);




    // Test



    tabButton.at(21).at(30)->setStyleSheet("background-color: red;");
    tabButton.at(21).at(30)->setDisabled(true);

    QPixmap pixmap(":/ressources/img/ant_side.svg");

    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/ressources/img/stone.svg");

    QIcon ButtonIcon2(pixmap2);

    QPixmap pixmap3(":/ressources/img/leaf.svg");

    QIcon ButtonIcon3(pixmap3);

    tabButton.at(3).at(3)->setIcon(ButtonIcon);

    tabButton.at(3).at(4)->setIcon(ButtonIcon2);
    tabButton.at(3).at(5)->setIcon(ButtonIcon2);
    tabButton.at(3).at(6)->setIcon(ButtonIcon2);
    tabButton.at(2).at(4)->setIcon(ButtonIcon2);
    tabButton.at(2).at(5)->setIcon(ButtonIcon2);

    tabButton.at(3).at(20)->setIcon(ButtonIcon3);

    // Create a widget
    QWidget *w = new QWidget();

    // Set the grid layout as a main layout
    w->setLayout(gridLayout);


    gridLayout->setSpacing(0);
    // Window title
    w->setWindowTitle("Grid Layouts");


    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();


    w->setFixedSize(QSize(width,height-70));

    w->setStyleSheet("background-color: rgb(255,255,255);");

    // Display
    w->show();
    // Event loop
    return app.exec();
}
