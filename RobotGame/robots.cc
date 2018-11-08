#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "robots.h"

using namespace std;

// generate a random robot
Robots::Robots(): luck{25}, strength{1500 + rand()%500}, defense{350 + rand()%350}, health{15000 + rand()%1000}, name{"The Challenger"} {}

Robots::Robots(int luck, int strength, int defense, int health, string name): luck{luck}, strength{strength}, 
    defense{defense}, health{health}, name{name} {}

// copy constructor
Robots::Robots(const Robots &robo): luck{robo.luck}, strength{robo.strength}, defense{robo.defense}, health{robo.health}, name{robo.name} {}

Robots &Robots::operator=(const Robots &robo) {
    // copying value
    luck = robo.luck;
    strength = robo.strength;
    defense = robo.defense;
    health = robo.health;
    name = robo.name;
    return *this;
}

Robots &Robots::operator=(Robots &&robo) {
    // copying value
    luck = robo.luck;
    strength = robo.strength;
    defense = robo.defense;
    health = robo.health;
    name = robo.name;
    return *this;
}

void Robots::reduceHealth(int damage) {
    // chance that the robot dodges and takes no damage
    if(rand()%500 < luck) {
        cout << name << " *dodges*" << endl;
        return;
    }
    health -= damage;
}

int Robots::getHealth() {
    return health;
}

string Robots::getName() {
    return name;

}

string Robots::getStats() {
    // retusn details of the robot
    return "Strength: " + to_string(strength) + " || Defense: " + to_string(defense) + " || Health: " + to_string(health) + " || Name: " + name;
}

bool validInt(int &value) {
    // will ensure the input is an int
    string s;
    cin >> s;

    istringstream iss{s};
    if(iss >> value) {
        return true;
    }
    else {
        return false;
    }
}

Robots *createPlayerRobot() {
    int luck = rand()%15;
    int strength, defense, health;
    string name;

    // get user customization
    do {
        cout << "Allocate stats for your build! You are given 10 tokens and you are able to distribute them to improve your robot's strength, defnse or health!" << endl << "To allocate the tokens, enter 3 positive numbers that add up to 10 and a name for your robot in the order: [Strength] [Defense] [Health] [Name]" << endl;
        if(!(validInt(strength) && validInt(defense) && validInt(health))) {
            getline(cin, name);
            cout << endl << "INVALID INPUT" << endl;
            continue;
        }
        cin >> name;
    } while(strength + defense + health != 10 && strength >= 0 && defense >= 0 && health >= 0);

    // adjust stats
    strength = 1600 + 50*strength;
    defense = 450 + 50 * defense;
    health = 15000 + 200 * health;

    cout << name + "'s stats are... Strength: " + to_string(strength) + " || Defense: " + to_string(defense) + " || Health: " + to_string(health) << endl;

    // return heap allocated robot
    return new Robots(luck, strength, defense, health, name);
}

int Robots::getStrength() {
    return strength;
}

int Robots::getDefense() {
    return defense;
}