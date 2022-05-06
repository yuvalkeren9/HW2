//
// Created by eladm on 02/05/2022.
//

#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H


#include <iostream>
#include "utilities.h"
using std::cout;
using std::endl;
using std::string;


/** Global variables defined below */
const int DEFAULT_MAX_HP = 100;
const int DEFAULT_FORCE = 5;

/** a class that represents a player type. The class hold the player's name, his current level, current force, his max HP, current player's HP, and
 * the amount of coins he has */
class Player {
    string m_name;   //Character's name           //ELAD ,SHOULD WE PUT HERE A CONST??
    int m_level;     //Player's level
    int m_force;     //Player's force
    int m_maxHP;     //Player's maximum HP allowed
    int m_HP;        //Player's current HP
    int m_coins;     //Player's amount of coins he currently holds


public:
    /** basic constructors for the Player type. Notice the build constructor is not default, and has default values if not attributed by user.
    * Also, a player will always be initialized with a level 1 and 0 coins.*/
    explicit Player(const string& name, const int maxHP = DEFAULT_MAX_HP ,const int force = DEFAULT_FORCE);
    Player(const Player& player) = default;
    ~Player() = default;
    Player& operator=(const Player&) = default;

    /** function that prints the Player's info */
    void printInfo() const;

    /** increases the player's level by 1 */
    Player& levelUp();

    /** getter functions */
    int getLevel() const;
    int getAttackStrength() const;

    /** increases the player's force by the amount received as argument */
    Player& buff(const int addedForce);

    /** increases the player's hp by the amount received as argument */
    Player& heal(const int addedHP);

    /** decreases the player's hp by the amount received as argument */
    Player& damage(const int damageInflicted);

    /** methods returns whether a player's hp is a 0 (returns true if hp is 0) */
    bool isKnockedOut() const;

    /** increases the player's amount of coins by the amount received as argument */
    Player& addCoins(const int numOfCoins);

    /** decreases the player's amount of coins by the amount received as argument. If player doesn't have enough coins, nothing will happen
     * and function will return false. If succeeded, true will be returned.*/
    bool pay(const int price);

};
#endif //HW2_PLAYER_H
