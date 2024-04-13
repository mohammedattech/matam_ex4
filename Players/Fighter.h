#ifndef Fighter_H
#define Fighter_H
#include "Player.h"
class Fighter:public Player{
public:
    Fighter(const std::string& name);
    int getAttackStrength() const override;
    Player* clone()const override;
private:
    void printPlayerInfo(std::ostream& os) const override;
};
#endif