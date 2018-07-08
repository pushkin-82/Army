#ifndef ARMY_OBSERVABLE_H
#define ARMY_OBSERVABLE_H

#include <set>
#include <iostream>
//#include "Observer.h"

class Necromancer;

class Observable {
    protected:
        std::set<Necromancer*> *observers;
        
    public:
        Observable();
        virtual ~Observable();
        
        void attach(Necromancer* unit);
        void detach(Necromancer* unit);
        virtual void notify();
        virtual void attachMarked(Necromancer* unit);
    
};


#endif //ARMY_OBSERVABLE_H
