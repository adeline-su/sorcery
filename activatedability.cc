#include "activatedability.h"
#include "player.h"
// class Player;
ActivatedAbility::ActivatedAbility(Player* target, int activationCost): target{target}, activationCost{activationCost} {}

// void BanishAbility::applyAbility(Card* c) {
//     if (c->getType != CardType::Ritual && c->getType != CardType::Minion) return false;
//     delete c;
//     return true;
// }

RechargeAbility::RechargeAbility() : ActivatedAbility{nullptr, 1} {}

void RechargeAbility::applyAbility(Player& player) {
    if (!player.getRitual()) return;
    player.getRitual()->increaseCharge(3);
}