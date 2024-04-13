#ifndef CARD_H
#define CARD_H
#include<iostream>
#include"../Players/Player.h"
class Card{
public: 
    Card(const std::string& name);
    virtual ~Card()=default;
    virtual void applyEncounter(Player& player) const =0;
    virtual Card* clone()const=0;
    friend std::ostream& operator<<(std::ostream& os,const Card& card);
protected: 
    virtual void PrintCardInfo(std::ostream& os) const=0;
    std::string m_name;
};
#endif