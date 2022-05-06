//
// Created by eladm on 06/05/2022.
//


#include "Mtmchkin.h"
#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using std::string;

Mtmchkin::Mtmchkin(const string& playerName, const Card* cardsArray, int numOfCards):m_playerName(playerName),
m_cardArray(cardsArray),m_numOfCards(numOfCards),m_gameStatus(GameStatus::MidGame),m_CurrentCardIndex(0) , m_player(playerName){
};

GameStatus Mtmchkin::getGameStatus() const{
    return this->m_gameStatus;
}

void Mtmchkin::playNextCard(Player& player)
{
 Card playCard=getPulledCard();
 playCard.printInfo();
 playCard.applyEncounter(player);
 updateGameStatus();
 player.printInfo();


}
bool  Mtmchkin::isOver(){
    return (this->m_gameStatus!=GameStatus::MidGame);
}
const Card& Mtmchkin::getPulledCard()
{
    if(this->m_numOfCards== this->m_CurrentCardIndex+1)
    {
        this->m_CurrentCardIndex=0;
    } else{
        this->m_CurrentCardIndex++;
    }
    return this->m_cardArray[m_CurrentCardIndex];

}
void Mtmchkin::updateGameStatus(){
    if(this->m_player.isKnockedOut())
    {
        this->m_gameStatus=GameStatus::Loss;
        return;
    }
    if(this->m_player.getLevel()==10)
    {
        this->m_gameStatus=GameStatus::Win;
        return;
    }
}