#ifndef FAIRY_H
#define FAIRY_H
#include"../Players/Player.h"
#include"Card.h"
#include<iostream>

class Fairy:public Card
{
public:
    Fairy();
    void applyEncounter(Player& player)const override;
    Card* clone()const override;
private:
    static const int HEAL_POINTS=10;
    void PrintCardInfo(std::ostream& os) const override;
};

#endif