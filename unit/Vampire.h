#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Unit.h"
#include "../ability/VampireAbility.h"

class VampireAbility;

class Vampire : public Unit {
	public:
		Vampire(const char* title = "Vampire", int hitPointsLimit = 200, int damage = 40);
		virtual ~Vampire();

        Vampire& turnToVampire(Unit* unit);
};

#endif // VAMPIRE_H
