//
// Created by Admin on 05.06.2022.
//
#pragma once
#include <iostream>

class Creature {
protected:
    int health_;

    int damage_;
    bool is_alive;
    void getHealth();
public:
    std::string name_;
    Creature();
    void takeDamage(int damage);
    void Attack(Creature *enemy,int damage);
    int getDamage();
    bool isAlive();
};
