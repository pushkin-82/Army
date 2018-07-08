#include "MagicState.h"

MagicState::MagicState(int manaLimit) {
    this->mana = manaLimit;
    this->manaLimit = manaLimit;
}

MagicState::~MagicState() {}


int MagicState::getMana() {
    return this->mana;
}

int MagicState::getManaLimit() {
    return this->manaLimit;
}


int MagicState::setManaLimit(int manaLimit) {
    this->manaLimit = manaLimit;
}


void MagicState::spendMana(int cost) {
    this->mana -= cost;

    if ( this->mana < 0 ) {
        throw NotEnoughManaException();
    }
}

void MagicState::addMana(int incMana) {
    this->mana += incMana;

    if ( this->mana > this->manaLimit ) {
        this->mana = this->manaLimit;
    }
}

