//
// Created by Admin on 05.06.2022.
//

#pragma once
#include "Creature.h"
#include "Dice.h"

using namespace std;

class Hero : public Creature {
public:
    Dice setOfDices[2];
    Hero();
    void setName(string name);
    int throwDices();
};