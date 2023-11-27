// Public interface for Enchantment Decorators

#ifndef __ENCHANTMENTDECCONCRETE_H__
#define __ENCHANTMENTDECCONCRETE_H__
#include <string>
#include "enchantmentdec.h"

class GiantStrength : public EnchantmentDec {
    public:
        GiantStrength(Minion* next);
        int getAttack() const override;
        int getDefense() const override;
        int getAction() const override;
        // Ability getAbility() const override; // ADD THIS BACK ONCE IMPLEMENTED ABILITIES
};

class Enrage : public EnchantmentDec {
    public:
        Enrage(Minion* next);
        int getAttack() const override;
        int getDefense() const override;
        int getAction() const override;
        // Ability getAbility() const override; // ADD THIS BACK ONCE IMPLEMENTED ABILITIES
};

class Haste : public EnchantmentDec {
    public:
        Haste(Minion* next);
        int getAttack() const override;
        int getDefense() const override;
        int getAction() const override;
        // Ability getAbility() const override; // ADD THIS BACK ONCE IMPLEMENTED ABILITIES
};

class MagicFatigue : public EnchantmentDec {
    public:
        MagicFatigue(Minion* next);
        int getAttack() const override;
        int getDefense() const override;
        int getAction() const override;
        // Ability getAbility() const override; // ADD THIS BACK ONCE IMPLEMENTED ABILITIES
};

class Silence : public EnchantmentDec {
    public:
        Silence(Minion* next);
        int getAttack() const override;
        int getDefense() const override;
        int getAction() const override;
        // Ability getAbility() const override; // ADD THIS BACK ONCE IMPLEMENTED ABILITIES
};

#endif
