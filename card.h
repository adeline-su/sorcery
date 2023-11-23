// This is the public interface for a card.

#ifndef __CARD_H__
#define __CARD_H__
#include <string>
using namespace std;

enum class CardType { Spell, Minion, Enchantment, Ritual };

// every card has a name and a cost
class Card {   
    string name;
    int cost;
    CardType type;
    string desc;

 public:
    Card(string cardName);
    virtual ~Card() = default;
    string getName() const;
    int getCost() const;

};

ostream &operator<< (ostream &out, const Card &c);

#endif