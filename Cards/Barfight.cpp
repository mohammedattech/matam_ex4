#include <iostream>
#include "../utilities.h"
#include "Barfight.h"
Barfight::Barfight():Card("Barfight")
{}
void Barfight::applyEncounter(Player& player) const
{
    const Fighter* fighter = dynamic_cast<Fighter*>(&player);
    if(fighter!=nullptr)
    {
        printBarfightMessage(true);
        return;
    }
    printBarfightMessage(false);
    player.damage(BARFIGHT_DAMAGE);
}
void Barfight::PrintCardInfo(std::ostream& os) const
{
    printCardDetails(os,m_name);
    printEndOfCardDetails(os);
}
Card* Barfight::clone()const
{
    return new Barfight(*this);
}