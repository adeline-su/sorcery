// This is the public interface for a card.

#ifndef __CARD_H__
#define __CARD_H__
#include <string>
using namespace std;

enum class CardType { Spell, Minion, Enchantment, Ritual };

// contains only minions for now
enum class CardName { 
    /* Minions: */ AirElemental, EarthElemental, BoneGolem, FireElemental, PotionSeller, NovicePyromancer, ApprenticeSummoner, MasterSummoner,
    /* Enchantments: */ GiantStrength, Enrage, Haste, MagicFatigue, Silence,
    /* Spells */ Banish, Unsummon, Recharge, Disenchant, RaiseDead, Blizzard,
    /* Rituals */ DarkRitual
};
string cardNameToString(CardName c);

// every card has a name and a cost
class Card {   
    CardName name;
    int cost;
    CardType type;
    string desc;
    bool needTarget; // true if the Card requires a target to be played

 public:
    // Card();
    Card(CardName cardName, int cost, CardType type, bool needTarget, string desc = "");
    virtual ~Card() = default;
    string getName() const;
    int getCost() const;
    CardType getType();
    bool getNeedTarget();

};

ostream &operator<< (ostream &out, const Card &c);

#endif
