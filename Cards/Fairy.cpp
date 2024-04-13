#include "Fairy.h"
#include "../Players/Wizard.h"
#include"../utilities.h"
Fairy::Fairy():Card("Fairy"){}

void Fairy::applyEncounter(Player& Player)const
{
        bool isWizard;
        const Wizard* wizard=dynamic_cast<Wizard*>(&Player);
        isWizard=(wizard!=nullptr);
        if(isWizard)
        {
                Player.heal(HEAL_POINTS);        
        }
        printFairyMessage(isWizard);
}
Card* Fairy::clone()const
{
        return new Fairy(*this);
}
void Fairy::PrintCardInfo(std::ostream& os) const
{
        printCardDetails(os,m_name);
        printEndOfCardDetails(os);
}