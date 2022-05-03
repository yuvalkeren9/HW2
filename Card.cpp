#include "Card.h"
#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using std::string;

Card::Card(CardType type, const CardStats& stats) :
    m_effect(type),
    m_stats(stats){
}


