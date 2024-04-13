#include"Pitfall.h"
#include"../utilities.h"
#include<iostream>
Pitfall::Pitfall():Card("Pitfall"){}
void Pitfall::applyEncounter(Player& player) const
{
    const Rouge* rouge = dynamic_cast<Rouge*>(&player);
    if(rouge!=nullptr)
    {
        printPitfallMessage(true);
        return;
    }
    printPitfallMessage(false);
    player.damage(PITFALL_DAMAGE);
}
void Pitfall::PrintCardInfo(std::ostream& os) const
{
    printCardDetails(os,m_name);
    printEndOfCardDetails(os);
}
Card* Pitfall::clone()const
{
    return new Pitfall(*this);
}