#include <utility>
#include "AntEgg.h"


AntEgg::AntEgg(const std::pair<int, int> &coord, int age, int color, int maxHp, int currentHp,int damageByHunger) : Ant(coord, age, color,
                                                                                                     maxHp,
                                                                                                     currentHp,
                                                                                                     damageByHunger)
{

}
