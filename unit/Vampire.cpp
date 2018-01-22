#include "Vampire.h"

Vampire::Vampire(const char* title, int hitPointsLimit, int damage) :
	Unit(title, hitPointsLimit, damage) {
		this->ability = new VampireAbility(this);
	}
Vampire::~Vampire() {}

Vampire& Vampire::turnToVampire(Unit* unit) {
    Vampire* vampire = new Vampire();

    unit->title = vampire.getTitle();
    unit->hitPointsLimit = vampire.getHitPointsLimit();
    unit->damage = vampire.getDamage();
    
    delete vampire;

    return *unit;
}

