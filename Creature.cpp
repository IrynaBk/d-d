//
// Created by Admin on 05.06.2022.
//
#include "Creature.h"

Creature::Creature() {}

void Creature::getHealth() {
    std::cout << name_ << " : " << health_ << " HP" << std::endl;
}
void Creature::takeDamage(int damage) {
    health_ -= damage;
    std::cout << name_ <<" отримує  -"<<damage <<"HP!" << std::endl;
    if (health_ <= 0) {
        this->health_ = 0;
        getHealth();
        std::cout << name_  << " помер." << std::endl;
        this->is_alive = false;
        return;
    }
    getHealth();
}
void Creature::Attack(Creature *enemy,int damage) {
    std::cout<<name_<<" атакував/ла!"<<std::endl;
    (*enemy).takeDamage(damage);
}
int Creature::getDamage() {
    return damage_;
}
bool Creature::isAlive() {
    return this->is_alive;
}