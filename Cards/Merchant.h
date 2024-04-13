#ifndef MERCHANT_H
#define MERCHANT_H
#include "Card.h"
class Merchant:public Card
{
private:
    static const int HEAL_POINTS=1;
    static const int BUFF=1;
    void PrintCardInfo(std::ostream& os) const override;
    static const int HEAL_COST=5;
    static const int BUFF_COST=10;
public:
    Card* clone()const override;
    void applyEncounter(Player& player) const override;
    Merchant();
    ~Merchant()=default;
};

#endif