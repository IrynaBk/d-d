cmake_minimum_required(VERSION 3.22)
project(D_Dconsole)

set(CMAKE_CXX_STANDARD 14)

add_executable(D_Dconsole main.cpp boost/di.h Creature.h Creature.cpp Hero.h Dice.h Hero.cpp NonPlayableCharacter.h NonPLayableCharacter.cpp Dragon.h Dragon.cpp Ork.h Ork.cpp Game.h Duel.h Duel.cpp Game.cpp)
