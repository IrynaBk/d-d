#include <iostream>
#include <cctype>
#include <map>
#include "vector"
#include "boost/di.h"
#include "Dice.h"
#include "Dragon.h"
#include "Ork.h"
#include "Hero.h"
#include "Duel.h"
#include "Game.h"
namespace di = boost::di;

bool continueGame(){
    cout<<"Хочеш продовжити досліджувати підземелля? (y/n)"<<endl;
    char c;
    cin>>c;
    c = tolower(c);
    while(c!='y' && c!='n'){
        cout<<"Нема такої опції, вибери ще раз."<<endl;
        cin>>c;
    }
    return c=='y';
}

int main() {
    system("chcp 65001");
    srand(time(NULL));
    Hero* player = new Hero();
    Game myGame(player);
    myGame.displayWelcomeMessage();
    auto injectorOrk = boost::di::make_injector(
            di::bind<Hero>.to<>(&*player),
            di::bind<Creature>.to<Ork>()
            );
    auto injectorDragon = boost::di::make_injector(
            di::bind<Hero>.to<>(&*player),
            di::bind<Creature>.to<Dragon>()
            );
    int roundCounter = 1;
    do{
        cout<<"********** Раунд "<<roundCounter<<" **********"<<endl;
        int num = myGame.generateNumberForMonster();
        auto myFight = injectorOrk.create<Duel>();
        if(num<31){
            myFight = injectorDragon.create<Duel>();
        }
        Duel *fight = &myFight;
        myGame.startFight(fight);
        if(!(myGame.isGameInProcess())){
            break;
        }
        if(!continueGame()){
            break;
        }
        roundCounter++;
    }while(1);
    myGame.displayFarewellMessage();
    return 0;
}
