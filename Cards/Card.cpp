#include"Card.h"
#include<iostream>
Card::Card(const std::string& name):m_name(name){}
std::ostream& operator<<(std::ostream& os,const Card& card)
{
    card.PrintCardInfo(os);   
    return os;
}