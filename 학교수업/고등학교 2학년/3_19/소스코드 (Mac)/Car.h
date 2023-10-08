//
//  Car.h
//  3_19
//
//  Created by 김종민 on 2015. 3. 19..
//  Copyright (c) 2015년 Jong-Min Kim. All rights reserved.
//

#ifndef ____19__Car__
#define ____19__Car__
// #pragma once     // Windows OS 전용

namespace CAR_CONST
{
    enum
    {
        ID_LEN    = 20,
        MAX_SPD   = 200,
        FUEL_STEP = 2,
        ACC_STEP  = 10,
        BRK_STEP  = 10
    };
}

class Car
{
private:
    char gamerID[CAR_CONST::ID_LEN];
    int  fuelGauge;
    int  curSpeed;
public:
    void InitMember(char * ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

#endif /* defined(____19__Car__) */
