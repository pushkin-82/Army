#include "Spell.h"
#include "../spellcaster/Spellcaster.h"

Spell::Spell(std::string title, int cost, int points) : title(title), cost(cost), points(points) {
    this->spellcaster = new Spellcaster();
}

Spell::~Spell() {}

std::string Spell::getTitle() const {
    return this->title;
}

int Spell::getCost() const {
    return this->cost;
}

int Spell::getPoints() const {
    return this->points;
}

Spellcaster* Spell::getSpellcaster() const {
    return this->spellcaster;
}

void Spell::setSpellcaster(Spellcaster* spellcaster) {
    this->spellcaster = spellcaster;
}

void Spell::action(Unit* target) {}

void Spell::action() {}


std::ostream& operator<<(std::ostream& out, const Spell& spell) {
    out << spell.getTitle() << ":\n";
    out << "Cost: " << spell.getCost() << "\n";
    out << "Action points: " << spell.getPoints() << "\n";

    return out;
}
