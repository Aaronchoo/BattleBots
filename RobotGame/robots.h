#include <string>
#ifndef ROBOT_H
#define ROBOT_H

class Robots {
    int luck;
    int strength;
    int defense;
    int health;
    std::string name;
    public:
        Robots();
        Robots(int, int, int, int, std::string);
        Robots(const Robots &);
        Robots(Robots &&);
        Robots &operator=(const Robots &);
        Robots &operator=(Robots &&);
        void reduceHealth(int);
        std::string getName();
        std::string getStats();
        int getHealth();
        int getStrength();
        int getDefense();
};

// will return heap allocated robot
Robots *createPlayerRobot();

#endif 