//
// Created by יובל קרן on 02/05/2022.
//

#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H
#include <iostream>
#include "utilities.h"
using std::cout;
using std::endl;
using std::string;

class Player {
    string m_name;
    int m_level, m_force, m_maxHP, m_HP, m_coins;


public:
    explicit Player(const string& name, const int maxHP = 100 ,const int force = 5);     //maybe put const here for compilation
    Player(const Player& player) = default;
    ~Player() = default;
    Player& operator=(const Player&) = default;
    void printInfo() const;
    Player& levelUp();
    int getLevel() const;
    Player& buff(const int addedForce);
    Player& heal(const int addedHP);
    Player& damage(const int damageInflicted);
    bool isKnockedOut() const;
    Player& addCoins(const int numOfCoins);
    bool pay(const int price);
    int getAttackStrength() const;


};
#endif //HW2_PLAYER_H