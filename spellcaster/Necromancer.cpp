#include "Necromancer.h"

Necromancer::Necromancer(std::string title, int hitPointsLimit, int damage, int mana)
    : Spellcaster(title, hitPointsLimit, damage, mana) {
        this->spell = new DeathWave();
        this->spellbook = new NecromancerSpellbook();
        this->setUndeadState(true);
        this->observables = new std::set<Unit*>();
    
}
Necromancer::~Necromancer() {
    delete this->observables;
}

void Necromancer::attack(Unit *enemy) {
    enemy->takeDamage(this->getDamage());
    if ( enemy->getHitPoints() > 0 ) {
        enemy->attach(this);
        this->attachMarked(enemy);
    }
}

void Necromancer::takeDamage(int dmg) {
    this->state->takeDamage(dmg);
    if ( this->getHitPoints() == 0 ) {
        this->notifyMarked();
    }
}

void Necromancer::takeMagicDamage(int dmg) {
    this->state->takeMagicDamage(dmg);
    if ( this->getHitPoints() == 0 ) {
        this->notifyMarked();
    }
}


void Necromancer::update(Unit* unit) {
    std::cout << "Start updating" << std::endl;
    unit->detach(this);
    this->addHitPoints(unit->getHitPointsLimit()/10);
    this->detachMarked(unit);
}

void Necromancer::attachMarked(Unit* marked) {
    observables->insert(marked);
    std::cout << this->getTitle() << " add Marked " << marked->getTitle() << std::endl;
}

void Necromancer::detachMarked(Unit* marked) {
    this->observables->erase(marked);
    std::cout << this->getTitle() << " delete Marked " << marked->getTitle() << std::endl;
}
void Necromancer::notifyMarked() {
    std::cout << "start notifying marked" << std::endl;
    std::set<Unit *>::iterator it;
    
    for (it = observables->begin(); it != observables->end(); ++it) {
        std::cout << " notifying marked " << (*it)->getTitle() << std::endl;
        
        (*it)->updateMarked(this);
        
    }
}
