#include "sorceryutil.h"

string cardNameToString(CardName c) {
    switch (c) {
        /* Minions: */
        case CardName::AirElemental:
            return "Air Elemental";
        case CardName::EarthElemental:
            return "Earth Elemental";
        case CardName::BoneGolem:
            return "Bone Golem";
        case CardName::FireElemental:
            return "Fire Elemental";
        case CardName::PotionSeller:
            return "Potion Seller";
        case CardName::NovicePyromancer:
            return "Novice Pyromancer";
        case CardName::ApprenticeSummoner:
            return "Apprentice Summoner";
        case CardName::MasterSummoner:
            return "Master Summoner";
        case CardName::Banish:
            return "Banish";
        case CardName::Unsummon:
            return "Unsummon";
        case CardName::Recharge:
            return "Recharge";
        case CardName::Disenchant:
            return "Disenchant";
        case CardName::RaiseDead:
            return "Raise Dead";
        case CardName::Blizzard:
            return "Blizzard";
            
        /* Enchantments: */
        case CardName::GiantStrength:
            return "Giant Strength";
        case CardName::Enrage:
            return "Enrage";
        case CardName::Haste:
            return "Haste";
        case CardName::MagicFatigue:
            return "Magic Fatigue";
        case CardName::Silence:
            return "Silence";
        case CardName::ModifyAttack:
            return "Modify Attack";
        case CardName::ModifyDefense:
            return "Modify Defense";
        case CardName::ModifyAbility:
            return "Modify Ability";

        /* Rituals: */
        case CardName::DarkRitual:
            return "Dark Ritual";
    }
}

Card* createCard(string cardName, Player* p) {
    Card* card;
    /* Minions: */
    if (cardName == "Air Elemental") card = new DefaultMinion(CardName::AirElemental, 0, 1, 1, monostate{});
    else if (cardName == "Earth Elemental") card = new DefaultMinion(CardName::EarthElemental, 3, 4, 4, monostate{});
    // minions with abilities: REPLACE MONOSTATE WITH ACTUAL ABILITY OBJECT ONCE THEY'RE MADE
    else if (cardName == "Bone Golem") card = new DefaultMinion(CardName::BoneGolem, 2, 1, 3, monostate{}, "Gain +1/+1 whenever a minion leaves play.");
    else if (cardName == "Fire Elemental") card = new DefaultMinion(CardName::FireElemental, 2, 2, 2, monostate{}, "Whenever an opponent's minion enters play, deal 1 damage to it.");
    else if (cardName == "Potion Seller") card = new DefaultMinion(CardName::PotionSeller, 2, 1, 3, monostate{}, "At the end of your turn, all your minions gain +0/+1.");
    else if (cardName == "Novice Pyromancer") card = new DefaultMinion(CardName::NovicePyromancer, 1, 0, 1, monostate{}, "Deal 1 damage to target minion.");
    else if (cardName == "Apprentice Summoner") card = new DefaultMinion(CardName::ApprenticeSummoner, 1, 1, 1, monostate{}, "Summon a 1/1 air elemental.");
    else if (cardName == "Master Summoner") card = new DefaultMinion(CardName::MasterSummoner, 3, 2, 3, monostate{}, "Summon up to three 1/1 air elementals.");

    /* Enchantments: */
    else if (cardName == "Giant Strength") card = new Enchantment(CardName::GiantStrength, 1, "", "+2", "+2");
    else if (cardName == "Enrage") card = new Enchantment(CardName::Enrage, 2, "", "*2", "*2");
    else if (cardName == "Haste") card = new Enchantment(CardName::Haste, 1, "Enchanted minion gains +1 action each turn");
    else if (cardName == "Magic Fatigue") card = new Enchantment(CardName::MagicFatigue, 0, "Enchanted minion's activated ability costs 2 more");
    else if (cardName == "Silence") card = new Enchantment(CardName::Silence, 1, "Enchanted minion cannot use abilities");
    
    /* Spells: */ 
    else if (cardName == "Banish") card = new Spell(CardName::Banish, 2, true, "Destroy target minion or ritual", new BanishAbility{});
    else if (cardName == "Unsummon") card = new Spell(CardName::Unsummon, 1, true, "Return target minion to its owner's hand", new UnsummonAbility{});
    else if (cardName == "Disenchant") card = new Spell(CardName::Disenchant, 1, true, "Destroy the top enchantment on target minion", new DisenchantAbility{});
    else if (cardName == "Raise Dead") card = new Spell(CardName::RaiseDead, 1, false, "Ressurect the top minion in your graveyard and set its defense to 1", new RaiseDeadAbility{});
    else if (cardName == "Recharge") card = new Spell(CardName::Recharge, 1, false, "Your ritual gains 3 charges", new RechargeAbility{});
    else if (cardName == "Blizzard") card = new Spell(CardName::Blizzard, 1, false, "Deals 2 damage to all minions", new BlizzardAbility{});
    

    /* Rituals: */ 
    else if (cardName == "Dark Ritual") card = new Ritual(CardName::DarkRitual, "At the start of your turn, gain 1 magic", 0, 1, 5, new DarkRitualAbility{p});
    // to do: add decorators (done?) and abilities to minions, add other kinds of cards
    else return nullptr;
    return card;
}

