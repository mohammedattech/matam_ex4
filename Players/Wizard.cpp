#include"Wizard.h"
#include"../utilities.h"
Wizard::Wizard(const std::string& name):Player(name){}
void Wizard::heal(const int healPoints){
    Player::heal(2*healPoints);
}
void Wizard::printPlayerInfo(std::ostream& os) const
{
    printPlayerDetails(os,m_name,"Wizard",m_level,this->getAttackStrength(),m_healthPoints.gethealth(),m_coins);
}
Player* Wizard::clone()const
{
    return new Wizard(*this);
}