//
// Created by Admin on 08.06.2022.
//
#pragma once

#include "Hero.h"

class Duel{
private:
    Creature* enemy;
    Hero* hero;
    bool hero_win;
public:
    Duel();
    Duel(Hero* hero, Creature* enemy);
    void battle();
    void displayDuelResult();
    bool getDuelResult();
};