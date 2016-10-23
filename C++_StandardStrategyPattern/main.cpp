//
//  main.cpp
//  C++_StandardStrategyPattern
//
//  Created by Ferenc Szalma on 9/27/16.
//  Copyright © 2016 Ferenc Szalma. All rights reserved.
//

#include <iostream>
using namespace std;


class GameCharacter;

class HealthCalcClass {
public:
    virtual int calc(const GameCharacter&) const {
        return 0;
    }
};

class SlowHealthDegr : public HealthCalcClass {
public:
    int calc(const GameCharacter&) const {
        return 5;
    };
};

HealthCalcClass defaultHealthCalc;

class GameCharacter {
public:
    explicit GameCharacter(HealthCalcClass *phcf = &defaultHealthCalc) : pHealthCalc(phcf) {};
    int healthValue() const {
        return pHealthCalc->calc(*this);
    }
    void setHealthCalcClass(HealthCalcClass& hcc) {
        pHealthCalc = &hcc;
    }
private:
    HealthCalcClass *pHealthCalc;
};

class BadEvilGuy : public GameCharacter {
public:
    explicit BadEvilGuy(HealthCalcClass * phcf) : GameCharacter(phcf) {};
};

int main(int argc, const char * argv[]) {
    SlowHealthDegr slow;
    BadEvilGuy ebg1(&slow);
    cout << ebg1.healthValue() << endl;
    HealthCalcClass defHealth;
    BadEvilGuy ebg2(&defHealth);
    cout << ebg2.healthValue() << endl;
    
    
    return 0;
}
