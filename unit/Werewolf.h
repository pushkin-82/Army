#ifndef WEREWOLF_H
#define WEREWOLF_H

#define FORCE_COEF 1.5

#include "Unit.h"
#include "../ability/WerewolfAbility.h"

class WerewolfAbility;

class Werewolf : public Unit {
    public:
        bool wolfState;

        Werewolf(std::string title = "Werewolf", int hitPointslimit = 150, int damage = 20);
        virtual ~Werewolf();

        void setWolfState(bool state);

        bool isWolf() const;
        void changeState();
        
        virtual void takeMagicDamage(int dmg);
};

#endif // WEREWOLF_H