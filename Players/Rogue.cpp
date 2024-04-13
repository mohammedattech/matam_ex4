
#include "Rogue.h"
#include "../utilities.h"
#include <iostream>
Rouge::Rouge(const std::string& name):Player(name)
{}
void Rouge::addCoins(int addedCoins)
{
    Player::addCoins(2*addedCoins);
}
void Rouge::printPlayerInfo(std::ostream& os) const
{
    printPlayerDetails(os,m_name,"Rouge",m_level,this->getAttackStrength(),m_healthPoints.gethealth(),m_coins);
}
Player* Rouge::clone()const
{
    return new Rouge(*this);
}