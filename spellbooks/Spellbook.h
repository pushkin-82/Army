#ifndef ARMY_SPELLBOOK_H
#define ARMY_SPELLBOOK_H

#include <map>
#include "../spell/Spell.h"
#include "../spell/MagicArrow.h"
#include "../spell/Heal.h"
#include "../spell/Summon.h"
#include "../spell/DeathWave.h"

class Spell;
class MagicArrow;
class DeathWave;
class Summon;
class Heal;

enum spells
{
    MAGIC_ARROW = 1,
    HEAL,
    SUMMON,
    DEATH_WAVE
};

class Spellbook {
    public:
        std::map<spells, Spell*>* spellbook;

        Spellbook();
        virtual ~Spellbook();
        
        void addSpell(spells spell);
        void deleteSpell(spells spell);
};

std::ostream& operator<<(std::ostream& out, const Spellbook& spellbook);

#endif //ARMY_SPELLBOOK_H
