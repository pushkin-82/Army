#ifndef ROGUE_H
#define ROGUE_H

#include "Unit.h"
#include "../ability/RogueAbility.h"

class Rogue : public Unit {
	public:
		Rogue(std::string title = "Rogue", int hitPointsLimit = 80, int damage = 20);
		virtual ~Rogue();
};

#endif //ROGUE_H