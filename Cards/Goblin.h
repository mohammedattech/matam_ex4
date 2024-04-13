#include "Battle.h"
#include "Card.h"
class Goblin:public Battle,public Card
{
private:
    static const int FORCE=6;
    static const int DAMAGE=10;
    static const int LOOT=2;
    void PrintCardInfo(std::ostream& os) const override;
public:
    Goblin();
    ~Goblin()=default;
    Card* clone()const override;
    bool fight(Player& player) const override;  
    void applyEncounter(Player& player) const override;
};
