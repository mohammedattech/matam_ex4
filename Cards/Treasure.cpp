#include "Treasure.h"
#include"../utilities.h"
Treasure::Treasure() : Card("Treasure")
{
}
Card *Treasure::clone() const
{
    return new Treasure(*this);
}
void Treasure::applyEncounter(Player &player) const
{
    printTreasureMessage();
    player.addCoins(ADDED_COINS);
}
void Treasure::PrintCardInfo(std::ostream& os) const
{
    printCardDetails(os,m_name);
    printEndOfCardDetails(os);
}