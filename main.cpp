#include <QtWidgets>
#include <QGridLayout>
#include <QApplication>
#include <QPushButton>
#include <vector>
#include <src/AntFighter.h>

#define M 50
#define N 100

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    // Grid layout with 3 buttons
    QGridLayout *gridLayout = new QGridLayout;
    std::vector<std::vector<QPushButton*>> tabButton(M, std::vector<QPushButton*>(N));

    std::pair<int,int> size(M,N);

    for(int i=0;i<size.first;i++)
    {
        for(int j=0;j<size.second;j++)
        {
            tabButton.at(i).at(j) = new QPushButton("");
            tabButton.at(i).at(j)->resize(15,15);
            tabButton.at(i).at(j)->setContentsMargins(0,0,0,0);
            //tabButton.at(i).at(j)->setStyleSheet("border: none;");
            gridLayout->addWidget(tabButton.at(i).at(j),i,j,1,1);
        }
    }



    AntFighter myAnt(<3,3>);







    //For pheromone?
    tabButton.at(21).at(30)->setStyleSheet("background-color: red;");
    tabButton.at(21).at(30)->setDisabled(true);

    //For ants
    QPixmap pixmap(":/ressources/img/ant_side.svg");

    QIcon ButtonIcon(pixmap);


    tabButton.at(3).at(3)->setIcon(ButtonIcon);


    // Create a widget
    QWidget *w = new QWidget();

    // Set the grid layout as a main layout
    w->setLayout(gridLayout);


    gridLayout->setSpacing(0);
    // Window title
    w->setWindowTitle("Grid Layouts");

    w->setFixedSize(QSize(1280,920));

    w->setStyleSheet("background-color: rgb(255,255,255);");

    // Display
    w->show();

    // Event loop
    return app.exec();
}
