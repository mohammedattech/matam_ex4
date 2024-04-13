#ifndef BATTLE_H
#define BATTLE_H
#include "Card.h" 
class Battle
{
public:
    Battle(int loot,int Damage,int force);
    ~Battle()=default;
    virtual bool fight(Player& player) const=0;
protected:
    int m_loot;
    int m_damage;
    int m_force;
};
#endif