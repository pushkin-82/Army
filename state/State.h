#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../exceptions.h"
#include "Undead.h"

class State : public Undead {
    protected:
        std::string title;
        int hitPoints;
        int hitPointsLimit;
        int damage;

    public:
        State(std::string title, int hitPointsLimit, int damage);
        virtual ~State();

        std::string getTitle() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;

        void setTitle(std::string title);
        void setHitPoints(int hp);
        void setHitPointsLimit(int hp);
        void setDamage(int dmg);


        void ensureIsAlive();

        virtual void addHitPoints(int hp);
        virtual void takeDamage(int dmg);
        virtual void takeMagicDamage(int dmg);
};

#endif //STATE_H
