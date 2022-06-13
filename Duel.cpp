//
// Created by Admin on 08.06.2022.
//
#include "Duel.h"

Duel::Duel(){}
Duel::Duel(Hero* hero_, Creature* enemy_){
    hero = hero_;
    enemy = enemy_;
    hero_win = false;
}
void Duel::battle(){
    cout<<"Бійка починається!"<<endl;
    cout<<hero->name_ <<" VS "<<enemy->name_<<endl;
    while(1) {
        int resultOfThrowing = hero->throwDices();
        if (resultOfThrowing <= 4) {
            cout << "Ну хто ж так б'є...ти нанесеш тільки половину урону." << endl;
            hero->Attack(enemy, hero->getDamage() / 2);
        } else if (resultOfThrowing == 12) {
            cout << "Оце ударище! Де тренувався/лася? Наносиш додатковий урон!" << endl;
            hero->Attack(enemy, hero->getDamage() + 2);
        } else {
            hero->Attack(enemy, hero->getDamage());
        }
        if(!enemy->isAlive()){
            cout<<"Файно ти його вбив/ла, хороша робота."<<endl;
            hero_win = true;
            delete enemy;
            enemy = nullptr;
            break;
        }
        cout<<"Час для атаки противника..."<<endl;
        enemy->Attack(hero,enemy->getDamage());
        if(!hero->isAlive()){
            cout<<"Тебе відлупцювали, сумно, звісно..."<<endl;
            hero_win = false;
            delete hero;
            hero = nullptr;
            break;
        }
    }
    displayDuelResult();
}
void Duel::displayDuelResult() {
    cout<<"Результат :"<<endl;
    if(hero_win){
        cout<<"Ти виграв/ла цю бійку."<<endl;
    }
    else{
        cout<<"Спочивай з миром, що сказати...."<<endl;
    }
}
bool Duel::getDuelResult() {
    return hero_win;
}