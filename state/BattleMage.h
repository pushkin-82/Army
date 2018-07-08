#ifndef ARMY_BATTLEMAGE_H
#define ARMY_BATTLEMAGE_H


class BattleMage {
    private:
        bool battleMage;
    public:
        BattleMage();
        virtual ~BattleMage();
    
        virtual bool isBattleMage();
        virtual void setBattleMageState(bool state);
};


#endif //ARMY_BATTLEMAGE_H
