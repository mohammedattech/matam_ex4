//
// created by Bashar Abulail and Mohammad Atrash
//
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include"../HealthPoints.h"
class Player
{
public:
    friend std::ostream& operator<<(std::ostream& os,const Player& player);
    /*
        -The constructor is made as requested in the Homework folder with defult paramaters to accommodate the requested paramters (name ,MaxHP and force)
        -The defult copy constructor,desturctor and operator= are used
    */
    Player(const std::string& name);
    Player(const Player &player) = default;
    virtual ~Player()=default;
    Player &operator=(const Player &player) = default;
    // The function PrintInfo() is used to print the player's information
    /*
        -The function levelUp() is used to increase the level of the player by 1
    */
    void levelUp();
    /*
        -The function getLevel() returns the level of the Player
        -@return - the level of the player
    */
    int getLevel() const;
    /*
        -The function buff() is used to increase the player's force
        -@param buffPoints - the size of the force increase
    */
    void buff(const int buffPoints);
    /*
        -The function heal() is used to increase the player's health until it reaches the max health
        -@param healPoints - the size of the health increase
    */
    bool isWon()const;
    virtual void heal(const int healPoints);
    /*
        -The function damage() is used to inflict damage on the player until he is knocked out(his health reaches zero)
        -@param damage - the damage that is inflicted upon the player
    */
    void damage(const int damage);
    /*
        -The function isKnockedout() is used to indicate of the players HP reached 0
        -@return
        -true if the player's HP is zero
        -false otherwise
    */
    bool isKnockedOut() const;
    /*
        -The function addCoins() increases the amount of coins that the player owns
        -@param addedCoins - the amount of coins given to the player
    */
    virtual void addCoins(const int addedCoins);
    /*
        -The function pay() deducts the number of coins from the player
        -@param cost - The amount of coins to be deducted from the player
        -@return
        -true if the payment was done successfully
        -false otherwise
    */
    bool pay(const int cost);
    /*
        -@return the Attack strength of the player
    */
    virtual int getAttackStrength() const;
    /*
        -the WINLEVEL constant is the maximum level that the player can reach
    */
    virtual Player* clone() const =0;
    static const int WINLEVEL = 10;
    /*
        -the following parameters are the defult values of maxHP and force
    */
    const std::string& getname() const;
    int getCurrentHealth() const;
    const int getCoins() const;
    static const int DEFAULT_MAX_HEALTH_POINTS = 100;
    static const int DEFAULT_FORCE = 5;
    static const int DEFAULT_LEVEL=1;
    static const int DEFAULT_COINS=10;
    static const int WIN_LEVEL=10;
protected:
    virtual void printPlayerInfo(std::ostream& os) const=0;
    std::string m_name;
    int m_level;
    int m_force;
    HealthPoints m_healthPoints;
    int m_coins;
};
#endif
