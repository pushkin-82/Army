#include "Spellcaster.h"

Spellcaster::Spellcaster(std::string title, int hitPointsLimit, int damage, int mana) :
    Unit(title, hitPointsLimit, damage) {
        this->magicState = new MagicState(mana);
        this->spellbook = new Spellbook();
    }

Spellcaster::~Spellcaster() {
    delete this->magicState;
    delete this->spell;
    delete this->spellbook;
}

int Spellcaster::getMana() const {
    return this->magicState->getMana();
}

int Spellcaster::getManaLimit() const {
    return this->magicState->getManaLimit();
}

MagicState* Spellcaster::getMagicState() const {
    return this->magicState;
}

Spell* Spellcaster::getSpell() const {
    return this->spell;
}

Spellbook* Spellcaster::getSpellbook() const {
    return this->spellbook;
}

bool Spellcaster::isBattleMage() {
    return this->magicState->isBattleMage();
}
void Spellcaster::setBattleMageState(bool state) {
    this->magicState->setBattleMageState(state);
}


void Spellcaster::spendMana(int cost) {
    this->ensureIsAlive();
    this->magicState->spendMana(cost);
}

void Spellcaster::addMana(int incMana) {
    this->ensureIsAlive();
    this->magicState->addMana(incMana);
}

void Spellcaster::cast(Unit* target) {
    this->spell->setSpellcaster(this);
    this->spendMana(this->spell->getCost());
    this->spell->action(target);
}

void Spellcaster::cast() {
    this->spell->setSpellcaster(this);
    this->spendMana(this->spell->getCost());
    this->spell->action();
}

void Spellcaster::changeSpell(spells newSpell) {
    std::map<spells, Spell*>::iterator it;
    
    it = this->spellbook->spellbook->find(newSpell);
    
    if ( it != this->spellbook->spellbook->end() ) {
        delete this->spell;
        this->spell = it->second;
    } else {
        std::cout << this->getTitle() << " can't cast this spell" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Spellcaster& spellcaster) {
    out << spellcaster.getTitle() << ":  ";
    out << "HP: " << spellcaster.getHitPoints() << "/" << spellcaster.getHitPointsLimit() << "  ";
    out << "Damage: " << spellcaster.getDamage() << "  ";
    out << "Mana: " << spellcaster.getMana() << "/" << spellcaster.getManaLimit() << "  ";
    out << "Current spell: " << spellcaster.getSpell()->getTitle() << "\n";

    return out;
}
