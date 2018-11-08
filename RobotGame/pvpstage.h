#include "stage.h"
#ifndef PVPSTAGE_H
#define PVPSTAGE_H

class PvpStage : public Stage {
    
    public:
        PvpStage();
        ~PvpStage();
        void introduction() override;
        void startBattle() override;
        void endGame() override;

};

#endif