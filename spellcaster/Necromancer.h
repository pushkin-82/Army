#ifndef ARMY_NECROMANCER_H
#define ARMY_NECROMANCER_H

#include "../interfaces/Observer.h"
#include "Spellcaster.h"
#include "../spell/DeathWave.h"
#include "../spellbooks/NecromancerSpellbook.h"

class Unit;

class Necromancer : public Spellcaster, public Observer {
    private:
        std::set<Unit*> *observables;
    
    public:
        Necromancer(std::string title="Necromancer", int hitPointsLimit=150, int damage=10, int mana=50);
        virtual ~Necromancer();
        
        virtual void attack(Unit* enemy);
        
        virtual void takeDamage(int dmg);
        virtual void takeMagicDamage(int dmg);
    
        virtual void update(Unit* unit);
        virtual void attachMarked(Unit* marked);
        virtual void detachMarked(Unit* marked);
        virtual void notifyMarked();
};


#endif //ARMY_NECROMANCER_H
