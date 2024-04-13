#ifndef PITFALL_H
#define PITFALL_H
#include "Card.h"
#include "../Players/Player.h"
#include "../Players/Rogue.h"
#include<iostream>
class Pitfall:public Card{
public: 
    Pitfall();
    Pitfall(const Pitfall&)=default;
    void applyEncounter(Player& player) const override;
    Card* clone()const override;
private:
    static const int PITFALL_DAMAGE=10;
    void PrintCardInfo(std::ostream& os) const override;
};

#endif