#include "Undead.h"

Undead::Undead() : undead(false) {}

Undead::~Undead() {}

bool Undead::isUndead() {
    return this->undead;
}

void Undead::setUndeadState(bool state) {
    this->undead = state;
}