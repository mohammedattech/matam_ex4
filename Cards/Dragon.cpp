#include "Dragon.h"
#include "../utilities.h"
Dragon::Dragon():Battle(LOOT,INFINITE_DAMAGE,FORCE),Card("Dragon")
{}
bool Dragon::fight(Player& player) const
{
    if(m_force<=player.getAttackStrength())
    {
        printWinBattle(player.getname(),m_name);
        return true;
    }
    else
    {
        printLossBattle(player.getname(),m_name);
        player.damage(player.getCurrentHealth());
    }
    return false;
}
void Dragon::applyEncounter(Player& player) const
{
    if(this->fight(player))
    {
        player.addCoins(m_loot);
        player.levelUp();
    }
}
Card* Dragon::clone()const
{
    return new Dragon(*this);
}
void Dragon::PrintCardInfo(std::ostream& os) const
{
    printCardDetails(os,m_name);
    printMonsterDetails(os,m_force,m_damage,m_loot,true);
    printEndOfCardDetails(os);
}