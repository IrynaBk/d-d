//
// Created by Admin on 05.06.2022.
//
#pragma once
#include <iostream>
//#include <utility>

class Dice {
private:
    int number;
public:
    void generateNumber() {
        number = 1+ rand() % 6;
    }
    int getNumber() {
        return number;
    }
    Dice() {}
};
