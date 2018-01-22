#ifndef BERSERKER_H
#define BERSERKER_H

#include "Unit.h"
#include "../ability/BerserkerAbility.h"
#include "../exceptions.h"

class Berserker : public Unit {
	public:
		Berserker(const char* title = "Berserker", int hitPointsLimit = 100, int damage = 15);
		virtual ~Berserker();

		void addHitPoints(int hp);
		void takeMagicDamage(int dmg);
};

#endif // BERSERKER_H