#include <iostream>
#include <string>
#include "pvpstage.h"

using namespace std;

void PvpStage::introduction() {
    // intro
    cout << "Welcome to the endless battle round! This will be a 1v1 gamemode! Have fun playing with your friend!" << endl;
    cout << "Let's being the challenge!!" << endl;

}

void PvpStage::startBattle() {
        // will ensure the robots are made
    if(getHomeRobot() == nullptr) {
        cout << "We will start by building the robot!" << endl;
        // gets player to change robot
        cout << "Make your robot player 1" << endl;
        changeHomeRobot(createPlayerRobot());
        cout << "Make your robot player 2" << endl;
        changeAwayRobot(createPlayerRobot());
    }
    
    // explianing the game
    cout << "The game will now begin! To play, enter [A] to attack and [D] to defend." << endl << "When you attack, you most you will damage your opponent is the strength of your robot while the least will be your attrack minus their defense." << endl << "When defending, there is a chance your defense will double or even triple." <<endl;
    
    // save data to temp Robots to fight
    Robots tempHome = Robots{*getHomeRobot()};
    Robots tempAway = Robots{*getAwayRobot()};
    string homeMove, awayMove;
    // the righting process
    while(tempHome.getHealth() > 0 && tempAway.getHealth() > 0) {

       
        // gets the moves
        homeMove = getMove(tempHome);
        awayMove = getMove(tempAway);

        // robots will either defend or attack
        robotFight(tempHome, tempAway, homeMove, awayMove);
        cout << "The stats are:" << endl << tempHome.getStats() << endl << tempAway.getStats() << endl;
    }

    // once someone losses the score will be added
    if(tempHome.getHealth() < 0) {
        addScore("away");
    } else {
        addScore("home");
    }

    cout << getScore() << endl;
}

void PvpStage::endGame() {
    // outro
    cout << "I hope you had fun playing! The final score is: " + getScore() << endl;
    gameStats();
    resetScore();
}