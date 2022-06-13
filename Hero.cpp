//
// Created by Admin on 05.06.2022.
//
#include "Hero.h"


Hero::Hero() {
    name_ = "Unknown";
    health_ = 20;
    damage_ = 4;
    is_alive = true;
}

void Hero::setName(string name) {
    name_ = name;
}
int Hero::throwDices() {
    cout<<name_ << " Кидає кубики!"<<endl;
    (setOfDices[0]).generateNumber();
    cout << "Перший кубик : " << (setOfDices[0]).getNumber() <<endl;
    (setOfDices[1]).generateNumber();
    cout << "Другий кубик : " << (setOfDices[1]).getNumber() <<endl;
    return (setOfDices[0]).getNumber() + (setOfDices[1]).getNumber();
}