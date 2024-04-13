#ifndef ROUGE_H
#define ROUGE_H
#include "Player.h"
#include <iostream>
class Rouge: public Player
{
public:
    Rouge(const std::string& name);
    ~Rouge()=default;
    void addCoins(int addedCoins) override;
    Player* clone()const override;
private:
    void printPlayerInfo(std::ostream& os) const override;
};
#endif