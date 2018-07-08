#ifndef OBSERVER_H
#define OBSERVER_H

#include "../unit/Unit.h"

class Unit;

class Observer {
    protected:
        std::set<Unit*> *observables;
    
    public:
		Observer();
		virtual ~Observer();
		
		virtual void update(Unit* unit) = 0;
		virtual void attachMarked(Unit* marked) = 0;
		virtual void detachMarked(Unit* marked) = 0;
		virtual void notifyMarked() = 0;

};

#endif //OBSERVER_H
