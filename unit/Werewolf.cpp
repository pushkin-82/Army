#include "Werewolf.h"

Werewolf::Werewolf(std::string title, int hitPointsLimit, int damage) : 
    Unit(title, hitPointsLimit, damage) {
        this->ability = new WerewolfAbility(this);
        this->wolfState = false;
        this->setUndeadState(true);
    }

Werewolf::~Werewolf() {
    delete this->ability;
}

void Werewolf::setWolfState(bool state) {
    this->wolfState = state;
}

bool Werewolf::isWolf() const {
    return this->wolfState;
}

void Werewolf::changeState() {
    std::string newName = "Wolf_";
    
    if ( !this->isWolf() ) {
        newName.append(this->getTitle());
        this->setTitle(newName);
        this->setHitPointsLimit(this->getHitPointsLimit()*FORCE_COEF);
        this->setHitPoints(this->getHitPointsLimit());
        this->setDamage(this->getDamage()*FORCE_COEF);
        this->setWolfState(true);
    } else {
        newName = this->getTitle().substr(5);
        this->setTitle(newName);
        this->setHitPointsLimit(this->getHitPointsLimit()/FORCE_COEF);
        this->setHitPoints(this->getHitPointsLimit());
        this->setDamage(this->getDamage()/FORCE_COEF);
        this->setWolfState(false);
    }
}

void Werewolf::takeMagicDamage(int dmg) {
    if ( this->isWolf() ) {
        this->state->takeMagicDamage(dmg*FORCE_COEF);
    } else {
        this->state->takeMagicDamage(dmg);
    }
}

