#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include "../unit/Unit.h"
#include "../state/MagicState.h"
#include "../spellbooks/Spellbook.h"
#include "../spell/Spell.h"

class Spell;

class Spellcaster : public Unit {
    protected:
        MagicState* magicState;
        Spell* spell;
        Spellbook* spellbook;

    public:
        Spellcaster(std::string title = "Spellcaster", int hitPointsLimit=10, int damage=10, int mana=10);
        virtual ~Spellcaster();

        int getMana() const;
        int getManaLimit() const;
        MagicState* getMagicState() const;
        Spell* getSpell() const;
        Spellbook* getSpellbook() const;
        virtual bool isBattleMage();
        
        virtual void setBattleMageState(bool state);

        void spendMana(int mana);
        void addMana(int incMana);

        virtual void cast(Unit* target);
        virtual void cast();
        void changeSpell(spells newSpell);
};

std::ostream& operator<<(std::ostream& out, const Spellcaster& spellcaster);

#endif // SPELLCASTER_H