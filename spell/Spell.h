#ifndef SPELL_H
#define SPELL_H

#include "../unit/Unit.h"

class Spellcaster;

class Spell {
    protected:
        Spellcaster* spellcaster;
        std::string title;
        int cost;
        int points;

    public:
        Spell(std::string title, int cost, int points);
        virtual ~Spell();

        std::string getTitle() const;
        int getCost() const;
        int getPoints() const;
        Spellcaster* getSpellcaster() const;

        void setSpellcaster(Spellcaster* spellcaster);

        virtual void action(Unit* target);
        virtual void action();
};

std::ostream& operator<<(std::ostream& out, const Spell& spell);


#endif // SPELL_H