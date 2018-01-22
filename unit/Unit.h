#ifndef UNIT_H
#define UNIT_H

#include "../state/State.h"
#include "../ability/Ability.h"

class Ability;

class Unit {
	protected:
		State* state;
		Ability* ability;
	
	public:
		Unit(const char* title, int hitPointsLimit, int damage);
		virtual ~Unit();

		const char* getTitle() const;
		int getHitPoints() const;
		int getHitPointsLimit() const;
		int getDamage() const;

		void ensureIsAlive();

		virtual void addHitPoints(int hp);
		virtual void takeDamage(int dmg);
		virtual void takeMagicDamage(int dmg);

		virtual void attack(Unit* enemy);
		virtual void counterAttack(Unit* enemy);
};

#endif //UNIT_H
