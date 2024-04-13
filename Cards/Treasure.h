#ifndef TREASURE_H
#define TREASURE_H
#include "Card.h"
class Treasure : public Card
{
private:
    static const int ADDED_COINS=10;
    void PrintCardInfo(std::ostream& os) const override;
public:
    Treasure();
    ~Treasure()=default;
    Card* clone()const override;
    void applyEncounter(Player& player) const override;
};
#endif