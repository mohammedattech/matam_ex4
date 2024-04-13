#include "Vampire.h"
#include"../utilities.h"
Vampire::Vampire():Battle(LOOT,DAMAGE,FORCE),Card("Vampire")
{}
bool Vampire::fight(Player& player) const
{
    if(m_force<=player.getAttackStrength())
    {
        printWinBattle(player.getname(),m_name);
        return true;
    }
    printLossBattle(player.getname(),m_name);
    player.damage(m_damage);
    return false;
}
void Vampire::applyEncounter(Player& player) const
{
    if(this->fight(player))
    {
        player.addCoins(m_loot);
        player.levelUp();
    }
}
Card* Vampire::clone()const
{
    return new Vampire(*this);
}
void Vampire::PrintCardInfo(std::ostream& os) const
{
    printCardDetails(os,m_name);
    printMonsterDetails(os,m_force,m_damage,m_loot);
    printEndOfCardDetails(os);
}