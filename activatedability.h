// Public interface for Ability

#ifndef __ACTIVATEDABILITY_H__
#define __ACTIVATEDABILITY_H__

#include "card.h"
#include <vector>
using namespace std;

class Player;

class ActivatedAbility {
    int activationCost = 0;
    virtual void doEffect(Player& player, int i = 0) = 0;
    bool hitBoth = false;
    bool needTarget;

    public:
        ActivatedAbility(int activationCost = 0, bool needTarget = false, bool hitBoth = false);
        virtual ~ActivatedAbility() = default;
        virtual void applyAbility(Player& player1, Player& player2, int i = 0);
        bool getNeedTarget();
        int getActivationCost();
        void incActivationCost(int n);
};

/* Abilities for Spells with targets: */

class BanishAbility : public ActivatedAbility{
    void doEffect(Player& player, int i = 0) override;
    public:
        BanishAbility();
        ~BanishAbility();
};

class UnsummonAbility : public ActivatedAbility{
    void doEffect(Player& player, int i = 0) override;
    public:
        UnsummonAbility();
        ~UnsummonAbility(); 
};

class DisenchantAbility : public ActivatedAbility{
    void doEffect(Player& player, int i = 0) override;
    public:
        DisenchantAbility();
        ~DisenchantAbility();
};

/* Abilities for Spells without targets: */

class RechargeAbility : public ActivatedAbility {
    void doEffect(Player& player, int i = 0) override;
    public:
        RechargeAbility();
        ~RechargeAbility();
};

class RaiseDeadAbility : public ActivatedAbility {
    void doEffect(Player& player, int i = 0) override;
    public:
        RaiseDeadAbility();
        ~RaiseDeadAbility();
};

// note: this is an ability that effects more than one player
class BlizzardAbility : public ActivatedAbility {
    void doEffect(Player& player, int i = 0) override;
    public:
        BlizzardAbility();
        ~BlizzardAbility();
};

/* Activated Abilities for Minions: */

class NovicePyromancerAbility : public ActivatedAbility {
    void doEffect(Player& player, int i = 0) override;
    public:
        NovicePyromancerAbility();
        ~NovicePyromancerAbility();
};

class ApprenticeSummonerAbility : public ActivatedAbility {
    void doEffect(Player& player, int i = 0) override;
    public:
        ApprenticeSummonerAbility();
        ~ApprenticeSummonerAbility();
};

class MasterSummonerAbility : public ActivatedAbility {
    void doEffect(Player& player, int i = 0) override;
    public:
        MasterSummonerAbility();
        ~MasterSummonerAbility();
};

class SilenceAbility : public ActivatedAbility {
    void doEffect(Player& player, int i = 0) override;
    public:
        SilenceAbility();
        ~SilenceAbility();
};



#endif
