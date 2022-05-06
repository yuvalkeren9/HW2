//
// Created by יובל קרן on 06/05/2022.
//


#include "Mtmchkin.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Mtmchkin::Mtmchkin(const string& playerName, const Card* cardsArray, int numOfCards) : m_playerName(playerName),
m_cardArray(cardsArray), m_numOfCards(numOfCards),m_gameStatus(GameStatus::MidGame),m_CurrentCardIndex(0) , m_player(m_playerName){
}

GameStatus Mtmchkin::getGameStatus() const{
    return this->m_gameStatus;
}

void Mtmchkin::playNextCard()
{
 Card playCard=this->m_cardArray[m_CurrentCardIndex];
 this->updateCardIndex();
 playCard.printInfo();
 playCard.applyEncounter(m_player);
 updateGameStatus();
 m_player.printInfo();
}

void Mtmchkin::updateCardIndex(){
    if(this->m_numOfCards== this->m_CurrentCardIndex+1)
    {
        this->m_CurrentCardIndex=0;
    } else{
        this->m_CurrentCardIndex++;
    }
}
bool  Mtmchkin::isOver(){
    return (this->m_gameStatus!=GameStatus::MidGame);
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