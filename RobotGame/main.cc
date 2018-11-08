#include <iostream>
#include <string>
#include "robots.h"
#include "stage.h"
#include "pvpstage.h"
#include "pvestage.h"

using namespace std;

istream &operator>>(istream &in, Robots *robo) {
    return in;
}

int main() {

    //Introduction message
    cout << "Welcome to BattleBots! The text based robot battling game! Enter [ANYTHING] to proceed..." << endl;
    
    string s;
    getline(cin, s);
    s = "Ignore";
    Stage *battleStage = nullptr;

    do {
        //Game options        
        if(s == "X") {
            //create a stage and start the game but have the battle be in a loop
            battleStage = new PvpStage();
        } else if(s == "A") {
            battleStage = new PveStage();
            //create a stage and start the game
        } else if(s == "Q") {
            break;
        }
        cout << "There are two gamemodes: 1 player versus the world or player versus player. Enter [A] to play the first gamemode or [X] to play the second" << endl;
        cout << "When youre done playing the game and decded to quit, type [Q] and the program will end." << endl;

        if(battleStage != nullptr) {
            battleStage->introduction();
                string temp = "Y";
                do {
                    if(temp == "N" || temp == "n") {
                        break;
                    }
                    //should have stats saved already
                    battleStage->startBattle();
                    cout << "To quit press [N]/[n], otherwise, press any button to keep playing" << endl;
                } while(cin >> temp);
            battleStage->endGame();
            delete battleStage;
            battleStage = nullptr;
        }
    } while(getline(cin,s));

    //Ending message
    cout << "Thanks for playing!! I hope you had fun!" << endl;
}