#include"Fighter.h"
#include"../utilities.h"
#include<iostream>
Fighter::Fighter(const std::string& name):Player(name){}
int Fighter::getAttackStrength()const{
    return 2*m_force+m_level;
}
void Fighter::printPlayerInfo(std::ostream& os) const
{
    printPlayerDetails(os,m_name,"Fighter",m_level,this->getAttackStrength(),m_healthPoints.gethealth(),m_coins);
}
Player* Fighter::clone()const
{
    return new Fighter(*this);
}