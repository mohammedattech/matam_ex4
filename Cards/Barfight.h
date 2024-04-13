#ifndef BARFIGHT_H
#define BARFIGHT_H
#include "Card.h"
#include "../Players/Player.h"
#include "../Players/Fighter.h"
#include <iostream>
class Barfight : public Card
{
public:
    Barfight();
    ~Barfight()=default;
    void applyEncounter(Player& player) const override;
    Card* clone()const override;
private:
    void PrintCardInfo(std::ostream& os) const override;
    static const int BARFIGHT_DAMAGE=10;
};

#endif