//
// Created by Admin on 06.06.2022.
//
#pragma once
#include "Duel.h"

class Game{
private:
    Hero* player;
    Duel* duel_;
    bool hero_win;
public:
    Game(Hero* player);
    void displayWelcomeMessage();
    void displayFarewellMessage();
    void startFight(Duel* fight);
    bool isGameInProcess();
    int generateNumberForMonster();
};

