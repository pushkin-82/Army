#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../exceptions.h"

class State {
    protected:
        const char* title;
        int hitPoints;
        int hitPointsLimit;
        int damage;

    public:
        State(const char* title, int hitPointsLimit, int damage);
        virtual ~State();

        const char* getTitle() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;

        void ensureIsAlive();

        virtual void addHitPoints(int hp);
        virtual void takeDamage(int dmg);
        virtual void takeMagicDamage(int dmg);
};

#endif //STATE_H
