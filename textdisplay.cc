#include <iostream>
#include <string>
#include "textdisplay.h"
#include "ascii_graphics.h"
#include "gamemaster.h"
using namespace std;

// print a card/board element
void print(const card_template_t &t) {
  for (auto row : t) { 
    cout << row << endl;
  }
}

// print cards from a vector of templates
void printCardRow(const vector<card_template_t> &ct) {
  for (int j = 0; j < 11; j++) {
    for (int i = 0; i < ct.size(); i ++){
      cout << ct[i][j];
    }
    cout << endl;
  }
}

// print the top/bottom board edge
void printTopBorder() {
  cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;
  for (int i = 0; i < 166; ++i) { 
    cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
  }
  cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << endl;
}

void printBottomBorder() {
  cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
  for (int i = 0; i < 166; ++i) { 
    cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
  }
  cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT << endl;
}

void TextDisplay::printPlayerBoardRow(int p) {
  // print the top row for player 1
  vector<card_template_t> toPrint;
  //cout << p << endl;

  // Print the ritual card
  string player_ritual_name = gm->getPlayer(p).getRitual()->getName();
  int player_r_cost = gm->getPlayer(p).getRitual()->getCost();
  int player_ritual_cost = gm->getPlayer(p).getRitual()->getActivationCost();
  string player_ritual_desc = gm->getPlayer(p).getRitual()->getDesc();
  int player_ritual_charges = gm->getPlayer(p).getRitual()->getCharge();

  toPrint.emplace_back(display_ritual(player_ritual_name, player_r_cost, player_ritual_cost, player_ritual_desc, player_ritual_charges));
  toPrint.emplace_back(CARD_TEMPLATE_EMPTY);

  // Print the name card
  string player_name = gm->getPlayer(p).getName();
  int player_life = gm->getPlayer(p).getLife();
  int player_mana = gm->getPlayer(p).getMagic();
  toPrint.emplace_back(display_player_card(p, player_name, player_life, player_mana));
  toPrint.emplace_back(CARD_TEMPLATE_EMPTY);

  // Print the graveyard card
  gm->getPlayer(1).getGrave().getGrave().top();

  string grave_name = gm->getPlayer(p).getGrave().getGrave().top()->getName();
  int grave_cost = gm->getPlayer(p).getGrave().getGrave().top()->getCost();
  int grave_attack = gm->getPlayer(p).getGrave().getGrave().top()->getAttack();
  int grave_defense = gm->getPlayer(p).getGrave().getGrave().top()->getDefense();
  toPrint.emplace_back(display_minion_no_ability(grave_name, grave_cost, grave_attack, grave_defense));
  
  printCardRow(toPrint);
  toPrint.clear();
}

// TextDisplay Constructor
TextDisplay::TextDisplay(GameMaster *_gm) : gm(_gm) {}

TextDisplay::~TextDisplay() = default;

void TextDisplay::displayMsg(string msg) {
    cout << msg << endl;
}

// Print the hand of player number [p] to stdout
// IF HAND IS EMPTY, PRINT EMPTY CARD
void TextDisplay::displayHand(int p) {
  int len = gm->getPlayer(p).getHand().getSize();

  // create a vector of all cardtemplates to print 
  vector<card_template_t> toPrint;

  // iterate through all items in the hand
  for (int i = 0; i < len; ++i) {

    string name = gm->getPlayer(p).getHand().getCard(i)->getName();
    string desc = gm->getPlayer(p).getHand().getCard(i)->getDesc();
    int cost = gm->getPlayer(p).getHand().getCard(i)->getCost();

    // if the card is an enchantment
    if (gm->getPlayer(p).getHand().getCard(i)->getType() == CardType::Enchantment) {
      toPrint.emplace_back(display_enchantment(name, cost, desc));
    
    //if the card is a spell
    } else if (gm->getPlayer(p).getHand().getCard(i)->getType() == CardType::Spell){
      toPrint.emplace_back(display_spell(name, cost, desc));

    // else, check the card one by one
    } else {
      // if minion:
      switch(gm->getPlayer(p).getHand().getCard(i)->getCardName()) {
        case(CardName::AirElemental):
          toPrint.emplace_back(display_minion_no_ability(name, cost, p, p));
          break;
        case(CardName::EarthElemental):
          toPrint.emplace_back(display_minion_no_ability(name, cost, 4, 4));
          break;
        case(CardName::BoneGolem):
          toPrint.emplace_back(display_minion_no_ability(name, cost, p, 3));
          break;
        case(CardName::FireElemental):
          toPrint.emplace_back(display_minion_no_ability(name, cost, 2, 2));
          break;
        case(CardName::PotionSeller):
          toPrint.emplace_back(display_minion_no_ability(name, cost, p, 3));
          break;
        case(CardName::NovicePyromancer):
          toPrint.emplace_back(display_minion_no_ability(name, cost, i, p));
          break;
        case(CardName::ApprenticeSummoner):
          toPrint.emplace_back(display_minion_no_ability(name, cost, p, p));
          break;
        case(CardName::MasterSummoner):
          toPrint.emplace_back(display_minion_no_ability(name, cost, 2, 3));
          break;

        // if ritual:
        case(CardName::DarkRitual):
          toPrint.emplace_back(display_ritual(name, cost, 1, desc, 5)); 
          break;
        // case(CardName::AuraOfPower):
        //   display_ritual(name, cost, 1, desc, 4); 
        //   cout << "ritual" << endl;
        //   break;
        // case(CardName::Standstill):
        //   display_ritual(name, cost, 2, desc, 4); 
        //   cout << "ritual" << endl;
        //   break;
      }
    }
    // go to the left of the current card, change the cursor position
    // moveup(11);
    // moveright(34);
  }
  printCardRow(toPrint);
}

void TextDisplay::displayMinion() {
}

void TextDisplay::displaySorceryBoard() {
  printTopBorder();
  printPlayerBoardRow(1);

  // create a vector of all cardtemplates to print 
  vector<card_template_t> toPrint;

  int len1 = gm->getPlayer(1).getBoard().getBoardSize();
  int len2 = gm->getPlayer(2).getBoard().getBoardSize();

  // PRINT the board for player 1
  for (int i = 0; i < len1; ++i) {
    string name = gm->getPlayer(1).getBoard().getCard(i)->getName();
    string desc = gm->getPlayer(1).getBoard().getCard(i)->getDesc();
    int cost = gm->getPlayer(1).getBoard().getCard(i)->getCost();
    int attack = gm->getPlayer(1).getBoard().getCard(i)->getAttack();
    int defense = gm->getPlayer(1).getBoard().getCard(i)->getDefense();
    toPrint.emplace_back(display_minion_no_ability(name, cost, attack, defense));
  }
  printCardRow(toPrint);
  toPrint.clear();

  // PRINT the center graphic
  print(CENTRE_GRAPHIC);

  // PRINT the board for player 2
  for (int i = 0; i < len2; ++i) {
    string name = gm->getPlayer(2).getBoard().getCard(i)->getName();
    string desc = gm->getPlayer(2).getBoard().getCard(i)->getDesc();
    int cost = gm->getPlayer(2).getBoard().getCard(i)->getCost();
    int attack = gm->getPlayer(2).getBoard().getCard(i)->getAttack();
    int defense = gm->getPlayer(2).getBoard().getCard(i)->getDefense();
    toPrint.emplace_back(display_minion_no_ability(name, cost, attack, defense));
  }
  printCardRow(toPrint);
  toPrint.clear();

  // print the top row for player 2
  printPlayerBoardRow(2);
  printBottomBorder();
}



