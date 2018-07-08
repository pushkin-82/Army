#ifndef ARMY_UNDEAD_H
#define ARMY_UNDEAD_H

class Undead {
    private:
        bool undead;
    public:
        Undead();
        virtual ~Undead();
    
        virtual bool isUndead();
        virtual void setUndeadState(bool state);
};

#endif //ARMY_UNDEAD_H
