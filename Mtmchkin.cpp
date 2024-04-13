#include"Mtmchkin.h"
#include"Exception.h"
#include"utilities.h"
#include"Cards/Fairy.h"
#include"Cards/Vampire.h"
#include"Cards/Goblin.h"
#include"Cards/Dragon.h"
#include"Cards/Merchant.h"
#include"Cards/Treasure.h"
#include"Cards/Pitfall.h"
#include"Cards/Barfight.h"
#include"Players/Wizard.h"
#include"Players/Fighter.h"
#include"Players/Rogue.h"
#include<iostream>
Mtmchkin::Mtmchkin(const std::string fileName):m_source(fileName),m_roundsCounter(0),m_currentCardIndex(0),
m_cardsNumber(0)
{
    if(!m_source)
    {
        throw DeckFileNotFound();
    }
    int line=0;
    std::string input;
    while(std::getline(m_source,input))
    {
        unique_ptr<Card>newCard=checkCard(input);
        if(!newCard)
        {
            throw DeckFileFormatError(line);
        }
        m_cards.push_back(checkCard(input));
        m_cardsNumber++;
        line++;
    }
    if(line<5)
    {
        throw DeckFileInvalidSize();
    }
    addPlayers();
}


void Mtmchkin::addPlayers()
{
    printStartGameMessage();
    printEnterTeamSizeMessage();
    std::cin>>m_teamSize;
    while(m_teamSize>6||m_teamSize<2)
    {
        printInvalidTeamSize();
        std::cin>>m_teamSize;
    }
    for (int i = 0; i < m_teamSize; i++)
    {
        printInsertPlayerMessage();
        std::string playerName;
        std::string playerClass;
        std::cin>>playerName;
        std::cin>>playerClass;
        unique_ptr<Player> player(checkPlayer(playerClass,playerName));
        while (player==nullptr)
        {
            printInvalidClass();
            std::cin>>playerName;
            std::cin>>playerClass;
            player=checkPlayer(playerClass,playerName);
        }
        m_players.push_back(std::move(player));
    }
}
 unique_ptr<Player> Mtmchkin::checkPlayer(const std::string& playerType,const std::string& playerName)
 {
    if(!validName(playerName))
    {
        return nullptr;
    }
    if(playerType=="Wizard")
    {
        return unique_ptr<Wizard>(new Wizard(playerName));
    }
    else if(playerType=="Fighter")
    {
        return unique_ptr<Fighter>(new Fighter(playerName));
    }
    else if(playerType=="Rouge")
    {
            
        return unique_ptr<Rouge>(new Rouge(playerName));
    }
    return nullptr;
 }

 unique_ptr<Card> Mtmchkin::checkCard(const std::string& cardType)
 {
    if(cardType=="Goblin")
    {
        return unique_ptr<Goblin>(new Goblin());
    }
    else if (cardType=="Vampire")
    {
        return unique_ptr<Vampire>(new Vampire());
    }
    else if (cardType=="Dragon")
    {
        return unique_ptr<Dragon>(new Dragon());
    }
    else if (cardType=="Merchant")
    {
        return unique_ptr<Merchant>(new Merchant());
    }
    else if(cardType=="Treasure")
    {
        return unique_ptr<Treasure>(new Treasure());
    }
    else if(cardType=="Pitfall")
    {
        return unique_ptr<Pitfall>(new Pitfall());
    }
    else if(cardType=="Barfight")
    {
        return unique_ptr<Barfight>(new Barfight());
    }
    else if(cardType=="Fairy")
    {
        return unique_ptr<Fairy>(new Fairy());
    }
    return nullptr;
 }


int Mtmchkin::getNumberOfRounds()const
{
    return m_roundsCounter;
}

bool Mtmchkin::isGameOver()const
{
    return m_teamSize==0;
}
bool Mtmchkin::validName(const std::string& name)const
{
    if(name.length()>MAX_NAME_LENGTH)
    {
        return false;   
    }
    for(char letter: name)
    {
        if (!((letter>='a'&&letter<='z')||(letter>='A'&&letter<='Z')))
        {
            return false;
        }
    }
    return true;
}

void Mtmchkin::playRound()
{
    printRoundStartMessage(m_roundsCounter);
    int playerSize=m_players.size();
    for (int i = 0; i < playerSize; i++)
    {
        if(m_currentCardIndex>=m_cardsNumber)
        {
            m_currentCardIndex=0;
        }
        unique_ptr<Player>temp=std::move(m_players.front());
        m_players.pop_front();
        m_cards[m_currentCardIndex]->applyEncounter(*temp);
        if(!temp->isKnockedOut()&&!temp->isWon())
        {
            m_players.push_back(std::move(temp));
        }
        else if(temp->isKnockedOut())
        {
            m_losers.push_front(std::move(temp));
            m_teamSize--;
        }
        else
        {
            m_winners.push_front(std::move(temp));
            m_teamSize--;
        }
        if(m_teamSize<=0)
        {
            printGameEndMessage();
        }
        m_currentCardIndex++;
    }
    m_roundsCounter++;
}

void Mtmchkin::printLeaderBoard()const
{   
    printLeaderBoardStartMessage();
    int ranking=1;
    for(unsigned int i=0;i<m_winners.size();i++)
    {
        printPlayerLeaderBoard(ranking,*m_winners.at(i));
        ranking++;
    }
    for(int i=0;i<m_teamSize;i++)
    {
        printPlayerLeaderBoard(ranking,*m_players.at(i));
        ranking++;
    }
    for(unsigned int i=0;i<m_losers.size();i++)
    {
        printPlayerLeaderBoard(ranking,*m_losers.at(i));
        ranking++;
    }
}
