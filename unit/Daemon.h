#ifndef DAEMON_H
#define DAEMON_H

#include "Unit.h"
#include "../ability/DaemonAbility.h"

class Warlock;

class Daemon : public Unit {
    private:
        Warlock* master;
    public:
        Daemon(std::string title = "Daemon", int hitPointsLimit = 80, int damage = 15);
        virtual ~Daemon();
    
        virtual void takeDamage(int dmg);
        virtual void takeMagicDamage(int dmg);
        
        Warlock* getMaster();
        
        void attachMaster(Warlock* master);
        void detachMaster(Warlock* master);

};

#endif //DAEMON_H