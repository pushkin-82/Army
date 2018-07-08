#include "Soldier.h"

Soldier::Soldier(std::string title, int hitPointsLimit, int damage):
    Unit(title, hitPointsLimit, damage) {
        this->ability = new SoldierAbility(this);
    }

Soldier::~Soldier() {
    delete this->ability;
}
