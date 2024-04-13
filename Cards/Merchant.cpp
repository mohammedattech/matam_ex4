#include "Merchant.h"
#include"../utilities.h"
#include <iostream>
Merchant::Merchant():Card("Merchant")
{}
void Merchant::PrintCardInfo(std::ostream& os) const
{
    printCardDetails(os,m_name);
    printEndOfCardDetails(os);
}
Card* Merchant::clone() const
{
    return new Merchant(*this);
}
void Merchant::applyEncounter(Player& player) const
{
    int PaidCoins=0;
    bool succesfullSale=false;
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getname(),player.getCoins());
    int Condition;
    if(player.getCoins()<HEAL_COST)
    {
        printMerchantInsufficientCoins(std::cout);
        succesfullSale=true;
    }
    while (!succesfullSale);
    {
        std::cin >> Condition;
        if(Condition==1)
        {
            if(player.pay(HEAL_COST))
            {
                PaidCoins+=HEAL_COST;
                player.heal(HEAL_POINTS);
            }
            else
            {
                printMerchantInsufficientCoins(std::cout);
            }
            succesfullSale=true;
        }
        else if (Condition==2)
        {
               if(player.pay(BUFF_COST))
            {
                PaidCoins+=BUFF_COST;
                player.buff(BUFF_COST);
            }
            else
            {
                printMerchantInsufficientCoins(std::cout);
            }
            succesfullSale=true;
        }
        else if(Condition==0)
        {
            succesfullSale=true;
        }
        else
        {
            printInvalidInput();
        }
    } 
    
    printMerchantSummary(std::cout,player.getname(),Condition,PaidCoins);
}