#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"
#include "../ability/SoldierAbility.h"

class Soldier : public Unit {
    public:
        Soldier(std::string title = "Soldier", int hitPointsLimit = 100, int damage = 10);
        virtual ~Soldier();
        
//        virtual
};

#endif //SOLDIER_H