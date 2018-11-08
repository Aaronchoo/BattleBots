#include "robots.h"
#ifndef STAGE_H
#define STAGE_H

class Stage {
    int homeScore = 0;
    int awayScore = 0;
    Robots *homeRobot = nullptr;
    Robots *awayRobot = nullptr;
    public:
        virtual void introduction() = 0;
        virtual void startBattle() = 0;
        virtual void endGame() = 0;

};
#endif