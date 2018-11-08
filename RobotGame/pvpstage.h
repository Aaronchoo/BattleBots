#include "stage.h"
#ifndef PVPSTAGE_H
#define PVPSTAGE_H

class PvpStage final : public Stage {
    
    public:
        void introduction() override;
        void startBattle() override;
        void endGame() override;

};
#endif