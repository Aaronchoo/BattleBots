#include <iostream>
#include <string>
#include "robots.h"
#include "stage.h"
#include "pvpstage.h"
#include "pvestage.h"

using namespace std;

istream &operator>>(istream &in, Robots *robo) {



}

int main() {

    //Introduction message
    cout << "Welcome to BattleBots! The text based robot battling game! Press [ENTER] to proceed..." << endl;
    
    string s;
    cin >> s;
    
    Stage *battleStage = nullptr;

    do {
        //Game options
        cout << "There are two gamemodes: 1 player versus the world or player versus player. Enter [A] to play the first gamemode or [X] to play the second" << endl;
        cout << "When youre done playing the game and decded to quit, type [QUIT!] and the program will end." << endl;
        if(s == "X") {
            //create a stage and start the game but have the battle be in a loop
            battleStage = new PvpStage();
        } else if(s == "A") {
            battleStage = new PveStage();
            //create a stage and start the game
        } else if(s == "QUIT!") {
            break;
        }
        if(battleStage != nullptr) {
            battleStage.Introduction();
                string temp = "Y";
                do {
                    if(temp == "N" || temp == "n") {
                        break;
                    }
                    //should have stats saved already
                    battleStage.battle();
                    cout << "To quit press [N]/[n], otherwise, press any button" << endl;
                } while(cin >> temp)
            battleStage.Ending();
            delete battleStage;
            battleStage = nullptr;
        }
    } while(cin >> s);

    //Ending message
    cout << "Thanks for playing!! I hope you had fun!" << endl;
}