#ifndef DRAGON_H
#define DRAGON_H
#include "Battle.h"
#include "Card.h"
class Dragon: public Battle ,public Card
{
private:
    static const int FORCE=25;
    static const int INFINITE_DAMAGE=100;
    static const int LOOT=1000;
    void PrintCardInfo(std::ostream& os) const override;
public:
    Dragon();
    ~Dragon()=default;
    Card* clone()const override;
    bool fight(Player& player) const override;
    void applyEncounter(Player& player) const override;
};


#endif