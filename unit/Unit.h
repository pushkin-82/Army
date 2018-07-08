#ifndef UNIT_H
#define UNIT_H

#include <set>
#include "../state/State.h"
#include "../ability/Ability.h"
#include "../interfaces/Observable.h"

class Ability;
class Necromancer;

class Unit : public Observable{
	protected:
		State* state;
		Ability* ability;
        std::set<Necromancer*> *observers;
	
	public:
		Unit(std::string title, int hitPointsLimit, int damage);
		virtual ~Unit();

		std::string getTitle() const;
		int getHitPoints() const;
		int getHitPointsLimit() const;
		int getDamage() const;
		State* getState() const;
		Ability* getAbility() const;
		bool isUndead() const;

        void setTitle(std::string title);
        void setHitPoints(int hp);
        void setHitPointsLimit(int hp);
        void setDamage(int dmg);
        void setState(State* state);
		void setAbility(Ability* ability);
		void setUndeadState(bool state);

		virtual void ensureIsAlive();

		virtual void addHitPoints(int hp);
		virtual void takeDamage(int dmg);
		virtual void takeMagicDamage(int dmg);

		virtual void attack(Unit* enemy);
		virtual void counterAttack(Unit* enemy);
		
        virtual void notify();
        virtual void updateMarked(Necromancer* unit);

};

std::ostream& operator<<(std::ostream& out, const Unit& unit);


#endif //UNIT_H
