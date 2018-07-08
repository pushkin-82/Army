#include "BattleMage.h"

BattleMage::BattleMage() : battleMage(false) {}

BattleMage::~BattleMage() {}

bool BattleMage::isBattleMage() {
    return this->battleMage;
}

void BattleMage::setBattleMageState(bool state) {
    this->battleMage = state;
}