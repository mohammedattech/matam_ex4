#include "Goblin.h"
#include "../utilities.h"
Goblin::Goblin():Battle(LOOT,DAMAGE,FORCE),Card("Goblin")
{}
bool Goblin::fight(Player& player) const
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
void Goblin::applyEncounter(Player& player) const
{
    if(this->fight(player))
    {
        player.addCoins(m_loot);
        player.levelUp();
    }
}
Card* Goblin::clone()const
{
    return new Goblin(*this);
}
void Goblin::PrintCardInfo(std::ostream& os) const
{
    printCardDetails(os,m_name);
    printMonsterDetails(os,m_force,m_damage,m_loot);
    printEndOfCardDetails(os);
}