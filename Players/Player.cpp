#include "Player.h"
#include "../utilities.h"
#include <string>
using std::string;
Player::Player(const std::string& name):m_name(name),
m_level(DEFAULT_LEVEL),m_force(DEFAULT_FORCE),m_healthPoints(DEFAULT_MAX_HEALTH_POINTS),
m_coins(DEFAULT_COINS)
{}
void Player::levelUp()
{
    if(m_level<WINLEVEL)
    {
        m_level++;
    }
}
int Player::getLevel() const
{
    return m_level;
}
void Player::buff(const int buffPoints)
{
    if(buffPoints<0)
    {
        return;
    }
    m_force+=buffPoints;
}
void Player::heal(const int healthPoints)
{
    m_healthPoints+=healthPoints;
}
void Player::damage(const int damage)
{
    if(damage<=0)
    {
        return;
    }
    m_healthPoints-=damage;
}
bool Player::isKnockedOut() const
{
    return m_healthPoints.gethealth()==0;
}
void Player::addCoins(const int addedCoins)
{
    if(addedCoins<=0)
    {
        return;
    }
    m_coins+=addedCoins;
}
bool Player::pay(const int cost)
{
    if(cost<0)
    {
        return true;
    }
    if(m_coins-cost>=0)
    {
        m_coins-=cost;
        return true;
    }
    return false;
}
int Player::getAttackStrength() const
{
    return m_force+m_level;
}
std::ostream& operator<<(std::ostream& os,const Player& player)
{
    player.printPlayerInfo(os);
    return os;
}
const std::string& Player::getname() const
{
    return m_name;
}
const int Player::getCoins() const
{
    return m_coins;
}
int Player::getCurrentHealth() const
{
    return m_healthPoints.gethealth();
}



bool Player::isWon()const
{
    return m_level==Player::WIN_LEVEL;
}