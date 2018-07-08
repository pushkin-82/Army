#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Unit.h"
#include "../ability/VampireAbility.h"

class VampireAbility;

class Vampire : public Unit {
	public:
		Vampire(std::string title = "Vampire", int hitPointsLimit = 200, int damage = 40);
		virtual ~Vampire();
};

#endif // VAMPIRE_H
