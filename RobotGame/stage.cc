#include <string>
#include <iostream>
#include "stage.h"

using namespace std;

Stage::~Stage() {
    delete homeRobot;
    delete awayRobot;
}

void Stage::changeHomeRobot(Robots* robo) {
    delete homeRobot;
    homeRobot = robo;
    return;
}

void Stage::changeAwayRobot(Robots* robo) {
    delete awayRobot;
    awayRobot = robo;
    return;
}

void Stage::addScore(string winner) {
    if(winner == "home") {
        homeScore +=1;
    } else {
        awayScore +=1;
    }
}

string Stage::getScore(){
    return homeRobot->getName + ": " + to_string(homeScore) + ": Challenger: " + to_string(awayScore);
}

Robots *Stage::getHomeRobot() {
    return homeRobot;
}

Robots *Stage::getAwayRobot() {
    return awayRobot;
}

void Stage::gameStats() {
    // retrieves stats from the robot
    cout << "The stats are:" << endl << homeRobot->getStats() << endl << awayRobot->getStats() << endl;
}

string Stage::getMove(Robots &temp) {
    string move;
    // will constantly ask for a valid input
    do {
        cout << temp.getName +" please press [A] to attack or [D] to defend";
        cin >> move;
    } while(move !="A" && move != "D"); 
    return move;
}

void robotFIght(Robots & tempHome, Robots &tempAway, std::string homeMove, std::string awayMove)  {
    // determines the result of both actions
    if(awayMove == homeMove && awayMove == "D") {
            cout << "Both robots decided to defend!" << endl;
        } else if(awayMove == homeMove) {
            cout << "Both robots decided to attack!!" << endl;

            tempHome.reduceHealth(tempAway.getStrength() - (tempHome.getDefense()/(rand()%10 + 1)));

            tempAway.reduceHealth(tempHome.getStrength() - (tempAway.getDefense()/(rand()%10 + 1)));
        } else if(awayMove == "D") {
            cout << tempHome.getName + " attacked!" << endl;

            tempAway.reduceHealth(tempHome.getStrength() - (tempAway.getDefense()*2/(rand()%15 + 1)));
        } else {
            cout << tempAway.getName + " attacked!" << endl;

            tempHome.reduceHealth(tempAway.getStrength() - (tempHome.getDefense()*2/(rand()%15 + 1)));
        }
}