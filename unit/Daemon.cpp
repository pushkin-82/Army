#include <cstddef>
#include "Daemon.h"
#include "../spellcaster/Warlock.h"

Daemon::Daemon(std::string title, int hitPointsLimit, int damage):
    Unit(title, hitPointsLimit, damage) {
        this->ability = new DaemonAbility(this);
        this->master = NULL;
    }

Daemon::~Daemon() {
    delete this->ability;
}

void Daemon::takeDamage(int dmg) {
    this->state->takeDamage(dmg);

    if ( this->getHitPoints() == 0 ) {
        this->master->detachDaemon();
        this->detachMaster(this->master);
    }
}

void Daemon::takeMagicDamage(int dmg) {
    this->state->takeMagicDamage(dmg);

    if ( this->getHitPoints() == 0 ) {
        this->master->detachDaemon();
        this->detachMaster(this->master);
    }
}

Warlock* Daemon::getMaster() {
    return this->master;
}

void Daemon::attachMaster(Warlock* master) {
    this->master = master;
}

void Daemon::detachMaster(Warlock* master) {
    delete this->master;
}

