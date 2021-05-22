#Documentaiton Ant colony


### Our goal
The goal of this project is to simulate the behavior of an ant colony.
It is developed as a school project in C++ with QT as a graphical library.

###Problematic
- How to simulate an ant ? 
- How to make all the ants move at the same time?
- How to simulate the egg laying of the queen ant ?
- How to simulate multiple ant colony?
- How to simulate an ant war ?
- How to simulate the apearance and disapearance of the food/obstacles ?
- How to make an ihm and place the food/obstacles in real time?



###Class Diagram
![Class Diagram](Class_Diagram.png)


###State Diagram of the ant evolution
![Evolution](Evolution_State_Diagram.png)

We stated that the ant will have a fix age at which they will evolve.

| Ant     | HP  | Age   |
|---------|-----|-------|
| Egg     | 30  | 0-10  |
| Larva   | 50  | 11-20 |
| Worker  | 100 | 21-30 |
| Fighter | 200 | 31-60 |
| Queen   | 500 | INF   |


###AntFighter State Diagram
![AntFighter](AntFighter_Stage_Diagram.png)



###  Rules




###  Dev tasks

- [x] Initialize the project
- [x] Prototype the IHM
- [x] Make all the classes, constructos/destructors and accessors
- [ ] Code a function to make an ant move - **Chloé**
- [ ] Display a colony by calling the constructor of the class - **Chloé**
- [x] Display a food source by calling the constructor of the class - **Chloé**
- [x] Display and obstacle by calling the constructor of the class - **Chloé**
- [ ] Make the pheromone display depending on its concentration (color) - **Nicolas**
- [x] Initialize a grid with default values - **Nicolas**
- [ ] Display the counter of the egg,larva,worker and fighter -  **Chloé**
- [ ] Develop the round system - **Nicolas**
- [ ] Make the queen produce egg - **Chloé**
- [ ] Make the evolution system & hunger system & age system- **Nicolas**
- [ ] Make the pheromone disapear other time - **Chloé et Nicolas**
- [ ] Make the pheromone decision system for the fighter ant - **Chloé et Nicolas**
- [ ] Make the fighter ant able to carry food and deposit it in the nest - **Chloé**
- [ ] Make food or obstacles with random chances - **Nicolas**
- [ ] On click, make food or obstacles (left or right click) - **Nicolas**
- [ ] **Optional** : Make a new queen
- [ ] **Optional** : Make the unitary tests

Dans AntFighter :

directionx= 0 ||1 ||-1

fourmi.at(coord.first+directionx).at(coord.first+directiony) = this;
fourmi.at(coord.first).at(coord.first)=NULL;
coord.second ++;
removeDisplay(coord.first).at(coord.first)
display(ANT_IMG,)