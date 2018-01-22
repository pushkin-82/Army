#include "State.h"

State::State(const char* title, int hitPointsLimit, int damage) {
    this->title = title;
    this->hitPoints = hitPointsLimit;
    this->hitPointsLimit = hitPointsLimit;
    this->damage = damage;
}

State::~State() {}

const char* State::getTitle() const {
    return this->title;
}

int State::getHitPoints() const {
    return this->hitPoints;
}

int State::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

int State::getDamage() const {
    return this->damage;
}

void State::ensureIsAlive() {
    if ( this->hitPoints == 0 ) {
        throw IsDeadException();
    }
}

void State::addHitPoints(int hp) {
    this->ensureIsAlive();

    this->hitPoints += hp;
    if ( this->hitPoints > this->hitPointsLimit ) {
        this->hitPoints = this->hitPointsLimit;
    }
}

void State::takeDamage(int dmg) {
    this->ensureIsAlive();

    if ( dmg > this->hitPoints ) {
        this->hitPoints = 0;
        return;
    }
    this->hitPoints -= dmg;
}

void State::takeMagicDamage(int dmg) {
    this->ensureIsAlive();

    if ( dmg > this->hitPoints ) {
        this->hitPoints = 0;
        return;
    }
    this->hitPoints -= dmg;
}
