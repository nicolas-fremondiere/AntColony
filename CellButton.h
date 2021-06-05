#include <QObject>
#include <QPushButton>

#ifndef CELL_H
#define CELL_H


class CellButton : public QPushButton
{
    Q_OBJECT
public:
    CellButton(std::pair<int,int> coord);
protected:

    void enterEvent(QEnterEvent *event);

private:

    std::pair<int,int> _coord;

};

#endif // CELL_H
