#ifndef WARLOCK_H
#define WARLOCK_H

#include "Spellcaster.h"
#include "../unit/Daemon.h"

class Daemon;

class Warlock : public Spellcaster {
    private:
    std::set<Daemon*> *daemon;
    public:
        Warlock(std::string title="Warlock", int hitPointsLimit=100, int damage=10, int mana=50);
        virtual ~Warlock();
    
        virtual void takeDamage(int dmg);
        virtual void takeMagicDamage(int dmg);
        
        virtual void cast();
        
        void attachDaemon();
        void detachDaemon();
        
        Daemon* getDaemon() const;
};

#endif // WARLOCK_H