#include "Soldier.h"

Soldier::Soldier(const char* title, int hitPointsLimit, int damage):
    Unit(title, hitPointsLimit, damage) {
        this->ability = new SoldierAbility(this);
    }

Soldier::~Soldier() {}
