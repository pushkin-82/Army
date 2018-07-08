#include "Unit.h"
#include "../spellcaster/Necromancer.h"

Unit::Unit(std::string title, int hitPointsLimit, int damage) {
	this->state = new State(title, hitPointsLimit, damage);
	this->ability = new Ability(this);
}

Unit::~Unit() {
	delete this->state;
}

std::string Unit::getTitle() const {
	return this->state->getTitle();
}

int Unit::getHitPoints() const {
	return this->state->getHitPoints();
}

int Unit::getHitPointsLimit() const {
	return this->state->getHitPointsLimit();
}

int Unit::getDamage() const {
	return this->state->getDamage();
}

State* Unit::getState() const {
    return this->state;
}

Ability* Unit::getAbility() const {
	return this->ability;
}

bool Unit::isUndead() const {
	return this->state->isUndead();
}

void Unit::setTitle(std::string title) {
	this->state->setTitle(title);
}

void Unit::setHitPoints(int hp) {
    this->state->setHitPoints(hp);
}

void Unit::setHitPointsLimit(int hp) {
	this->state->setHitPointsLimit(hp);
}

void Unit::setDamage(int dmg) {
	this->state->setDamage(dmg);
}

void Unit::setState(State *state) {
	delete(this->state);
	this->state = state;
}

void Unit::setAbility(Ability* ability) {
	delete(this->ability);
	this->ability = ability;
}

void Unit::setUndeadState(bool state) {
	this->state->setUndeadState(state);
}

void Unit::ensureIsAlive() {
	this->state->ensureIsAlive();
}


void Unit::addHitPoints(int hp) {
	this->state->addHitPoints(hp);
}

void Unit::takeDamage(int dmg) {
	this->state->takeDamage(dmg);
	if ( this->getHitPoints() == 0 ) {
	    this->notify();
	}
}

void Unit::takeMagicDamage(int dmg) {
	this->state->takeMagicDamage(dmg);
    if ( this->getHitPoints() == 0 ) {
        this->notify();
    }
}

void Unit::attack(Unit* enemy) {
	this->ability->attack(enemy);
}

void Unit::counterAttack(Unit* enemy) {
	this->ability->counterAttack(enemy);
}

//void Unit::attach(Necromancer* unit) {
//	observers->insert(unit);
//	std::cout << "Add Observer" << std::endl;
//}
//
//void Unit::detach(Necromancer* unit) {
//	observers->erase(unit);
//	std::cout << "Delete Observer" << std::endl;
//}

void Unit::notify() {
	std::set<Necromancer*>::iterator it;
	
	for (it = observers->begin(); it != observers->end(); ++it) {
		std::cout << " notifying" << std::endl;
		std::cout << (*it)->getTitle() << std::endl;

		(*it)->update(this);
	}

}

void Unit::updateMarked(Necromancer *unit) {
	std::cout << "Start updating marked" << std::endl;
	unit->detachMarked(this);
	this->detach(unit);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getTitle() << " [";
    out << unit.getHitPoints() << "/" << unit.getHitPointsLimit() << ", ";
    out << unit.getDamage() << "]\n";

	return out;
}