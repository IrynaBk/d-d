//
// Created by Admin on 09.06.2022.
//

#include "Game.h"

Game::Game(Hero *player_) {
    player = player_;
    duel_ = nullptr;
    hero_win = true;
}
void Game::displayWelcomeMessage() {
    std::cout<< "Вітаю дівчино або хлопче!" << endl;
    cout << "Шукаєш пригод?Так, розумію...Спершу, скажи своє ім'я : " << endl;
    string name;
    cin >> name;
    player->setName(name);
    cout<<"Ти заходиш в підземелля повне монстрів, які вже зачекалися на здобич..."<<endl;
}
void Game::displayFarewellMessage(){
    cout<<"Дякую, що пограла/в мою гру!"<<endl;
}
void Game::startFight(Duel *fight) {
    duel_ = fight;
    duel_->battle();
    hero_win = duel_->getDuelResult();
    delete duel_;
    duel_ = nullptr;
}
bool Game::isGameInProcess() {
    return hero_win;
}
int Game::generateNumberForMonster() {
    return 1+ rand() % 100;
}