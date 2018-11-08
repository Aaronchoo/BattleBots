#include "stage.h"
#ifndef PVESTAGE_H
#define PVESTAGE_H

class PveStage : public Stage {
    public:
        PveStage();
        ~PveStage();
        void introduction() override;
        void startBattle() override;
        void endGame() override;

};

#endif