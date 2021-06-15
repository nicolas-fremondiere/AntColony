
#include "Pheromone.h"
#include "GridManager.h"


Pheromone::Pheromone(std::pair<int, int> &coord, float concentration) :
    _coord(coord), _concentration(concentration) {}

const std::pair<int, int> &Pheromone::getCoord() const {
    return _coord;
}

void Pheromone::setCoord(const std::pair<int, int> &coord) {
    _coord = coord;
}


float Pheromone::getConcentration() const {
    return _concentration;
}

void Pheromone::setConcentration(float concentration) {
    _concentration = concentration;
}

void Pheromone::addConcentration(int amount)
{
  _concentration += amount;
  if(_concentration>127)
  {
      _concentration=127;
  }
}

void Pheromone::decayConcentration(int amount)
{
  if(_concentration > 0)
    _concentration -= amount;
  if(_concentration < 0)
    _concentration=0;
}

void Pheromone::updateDisplay(){
    int concentration = 255-this->_concentration*2;
    if(concentration<0)
        concentration=0;


    std::string concentrationStr = std::to_string(concentration);
    char* char_style;
    std::string str_style("background-color: rgb(255," + concentrationStr + ",255); border: none;");
    char_style = &str_style[0];;

    GridManager::getInstance().getButtonGrid().at(_coord.first).at(_coord.second)->setStyleSheet(char_style);
}
