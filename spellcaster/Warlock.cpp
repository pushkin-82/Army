#include <cstddef>
#include "Warlock.h"
#include "../spellbooks/WarlockSpellbook.h"

Warlock::Warlock(std::string title, int hitPointsLimit, int damage, int mana)
    : Spellcaster(title, hitPointsLimit, damage, mana) {
        this->spell = new Summon();
        this->spellbook = new WarlockSpellbook();
        this->daemon = new std::set<Daemon*>();
        this->setBattleMageState(true);
    }

Warlock::~Warlock() {
    delete this->daemon;
}

void Warlock::takeDamage(int dmg) {
    this->state->takeDamage(dmg);
    if ( this->getHitPoints() == 0 ) {
        this->detachDaemon();
    }
}

void Warlock::takeMagicDamage(int dmg) {
    this->state->takeMagicDamage(dmg);
    if ( this->getHitPoints() == 0 ) {
        this->detachDaemon();
    }
}


void Warlock::cast() {
    std::set<Daemon*>::iterator it;

    this->spell->setSpellcaster(this);
    this->spendMana(this->spell->getCost());
    this->spell->action();
    if ( this->spell->getTitle() == "Summon daemon" ) {
        this->attachDaemon();
        it = this->daemon->begin();
        std::cout << " Attach master to Daemon" << std::endl;
        
        (*it)->attachMaster(this);
    }
}

void Warlock::attachDaemon() {
    Daemon* summonedDaemon = new Daemon();
    this->daemon->insert(summonedDaemon);
    std::cout << "Summon Daemon" << std::endl;
}

void Warlock::detachDaemon() {
    std::set<Daemon*>::iterator it;
    
    it = this->daemon->begin();
    std::cout << " Kill Daemon" << std::endl;
    
    this->daemon->erase(it);
}

Daemon* Warlock::getDaemon() const {
    std::set<Daemon*>::iterator it;
    it = this->daemon->begin();
    if ( *it == NULL ) {
        std::cout << "There is no daemon" << std::endl;
        throw NoDaemonException();
    }
    return *it;
}