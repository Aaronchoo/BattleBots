#include "robots.h"
#ifndef STAGE_H
#define STAGE_H

class Stage {
    int homeScore = 0;
    int awayScore = 0;
    Robots *homeRobot = nullptr;
    Robots *awayRobot = nullptr;
    protected:
        void changeHomeRobot(Robots*);
        void changeAwayRobot(Robots*);
        void addScore(std::string);
        std::string getScore();
        Robots *getHomeRobot();
        Robots *getAwayRobot();
    public:
        virtual ~Stage();
        virtual void introduction() = 0;
        virtual void startBattle() = 0;
        virtual void endGame() = 0;
        void gameStats();
        std::string getMove(Robots &);
        void robotFight(Robots &, Robots &, std::string, std::string);
    

};
#endif