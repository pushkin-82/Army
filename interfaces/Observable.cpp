#include "Observable.h"
#include "../spellcaster/Necromancer.h"

Observable::Observable() {
    this->observers = new std::set<Necromancer*>();
}

Observable::~Observable() {
    delete this->observers;
}

void Observable::attach(Necromancer* unit) {
    observers->insert(unit);
    std::cout << "Add Observer" << std::endl;
}

void Observable::detach(Necromancer* unit) {
    observers->erase(unit);
    std::cout << "Delete Observer" << std::endl;
}

void Observable::notify() {
//    std::cout << "Start notifying" << std::endl;
//
//    std::set<Necromancer*>::iterator it;
//
//    for (it = observers->begin(); it != observers->end(); ++it) {
//        std::cout << " notifying" << std::endl;
//        std::cout << *it << std::endl;
//
//        (*it)->update(this);
//    }

}

void Observable::attachMarked(Necromancer* unit) {}

