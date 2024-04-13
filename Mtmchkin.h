#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include<iostream>
#include <utility>
#include<vector>
#include<deque>
#include<memory>
#include<fstream>
#include<stack>
#include<queue>
#include"Players/Player.h"
#include"Cards/Card.h"
using std::vector;
using std::deque;
using std::ifstream;
using std::unique_ptr;
using std::stack;
using std::queue;
class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    Mtmchkin(const Mtmchkin&)=delete;
    Mtmchkin& operator=(const Mtmchkin&)=delete;
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
private:
    ifstream m_source;
    int m_roundsCounter;
    int m_currentCardIndex;
    int m_cardsNumber;
    vector<unique_ptr<Card>>m_cards;
    deque<unique_ptr<Player>>m_players;
    deque<unique_ptr<Player>>m_winners;
    deque<unique_ptr<Player>>m_losers;
    int m_teamSize;
    unique_ptr<Card> checkCard(const std::string& cardType);
    unique_ptr<Player> checkPlayer(const std::string& playerType,const std::string& playerName);
    void addPlayers();
    bool validName(const std::string& name)const;
    static const int MAX_NAME_LENGTH=15;
};



#endif /* MTMCHKIN_H_ */
