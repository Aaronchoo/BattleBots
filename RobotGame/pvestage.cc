#include <string>
#include <iostream>
#include "pvestage.h"

using namespace std;

void PveStage::introduction() {
    // intro
    cout << "Welcome to the endless battle round! You will face robots that will come in all shapes and sizes." << endl;
    cout << "Let's being the challenge!!" << endl;
}

void PveStage::startBattle() {
    // initialization
    if(getHomeRobot() == nullptr) {
        cout << "We will start by building the robot!" << endl;
        // gets player to change robot
        changeHomeRobot(createPlayerRobot());
    }
    changeAwayRobot(new Robots());
    
    // explanation
    cout << "The game will now begin! To play, enter [A] to attack and [D] to defend." << endl << "When you attack, you most you will damage your opponent is the strength of your robot while the least will be your attrack minus their defense." << endl << "When defending, there is a chance your defense will double or even triple." << endl;

    // creating temp robots
    Robots tempHome = Robots{*getHomeRobot()};
    Robots tempAway = Robots{*getAwayRobot()};

    // start the fight
    while(tempHome.getHealth() > 0 && tempAway.getHealth() > 0) {

        // gets the move
        string homeMove, awayMove = "A";
        homeMove = getMove(tempHome);
        if(tempAway.getHealth() < rand()%5000) {
            awayMove = "D";
        }

        // robots make their move
        robotFight(tempHome,tempAway, homeMove, awayMove);
        cout << "The stats are:" << endl << tempHome.getStats() << endl << tempAway.getStats() << endl;
    }

    // score is updated
    if(tempHome.getHealth() < 0) {
        addScore("away");
    } else {
        addScore("home");
    }
    cout << getScore() << endl;
}

void PveStage::endGame() {
    //outro
    cout << "I hope you had fun playing! The final score is: " + getScore() << endl;
    cout << "The stats are:" << endl << getHomeRobot()->getStats() << endl; 
    resetScore();
}