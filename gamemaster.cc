#include <fstream>
#include <string>
#include <iostream>
#include "gamemaster.h"
using namespace std;

GameMaster::GameMaster() {} 
GameMaster::~GameMaster() {} 


// SET PLAYERS, ask Players for their names
void GameMaster::initPlayers(ifstream& deck1In, ifstream& deck2In) {
    // players:
    string p1name, p2name;
    cout << "Please enter player names: " << endl;
    getline(cin, p1name); 
    getline(cin, p2name); 

    Player p1, p2;
    p1.init(p1name, 1, deck1In);
    p2.init(p2name, 2, deck2In);

    cout << "Player " << p1.getId() << ": " << p1.getName() << endl;
    cout << "Player " << p2.getId() << ": " << p2.getName() << endl;

    p1.TEST_printPlayerDeck();
    p2.TEST_printPlayerDeck();

}

// // SET DECKS, initialize Decks
// void GameMaster::initDecks(ifstream& deck1In, ifstream& deck2In) {
//     Deck deck1, deck2;
//     deck1.init(deck1In);
//     deck2.init(deck2In);

//     cout << "Player 1's Deck: " << endl;
//     deck1.TEMP_printDeck();
//     cout << "Player 2's Deck: " << endl;
//     deck2.TEMP_printDeck();
// }

// starts a turn, switches active and nonactive players, notifies corresponding observers
void GameMaster::startTurn() {
    swap(activePlayer, nonactivePlayer);
    activePlayer->increaseMagic(1);
    cout << "Player " << turn << " : " << activePlayer->getName() << "  It's your turn!"
    // notify
}

// ends a turn, notifies corresponding observers
void GameMaster::endTurn() {
    ++turn;
    if (turn > numPlayers) {
        turn = 1;
    }
    // notify end of turn observers
}

void attackMinion();


void GameMaster::attackPlayer(int i) {
    Minion* attackingMinion = activePlayer->getMinion(i);
    int attackVal = attackingMinion->getAttack();
    nonactivePlayer->decreaseLife(attackVal);
}

void activateAbility();

void discard();

void GameMaster::play(int i) {
    activePlayer->play(i);
}

void notifyObservers();

// displays some visual
void describe();
void hand();
void board();

