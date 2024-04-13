#ifndef WIZARD_H
#define WIZARD_H
#include"Player.h"
#include<iostream>
class Wizard:public Player{
public:
    Wizard(const std::string& name);
    void heal(const int healPoints)override;
    Player* clone()const override;
private:
    void printPlayerInfo(std::ostream& os) const override;
};
#endif