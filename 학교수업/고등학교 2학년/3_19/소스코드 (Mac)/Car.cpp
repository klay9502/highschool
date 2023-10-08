//
//  Car.cpp
//  3_19
//
//  Created by 김종민 on 2015. 3. 19..
//  Copyright (c) 2015년 Jong-Min Kim. All rights reserved.
//

#include <iostream>
#include <cstring>

#include "Car.h"

using namespace std;

void Car::InitMember(char *ID, int fuel)
{
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState()
{
    cout << "소유자ID: " << gamerID << endl;
    cout << "연료랑: " << fuelGauge << "%" << endl;
    cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel()
{
    if (fuelGauge <= 0)
    {
        return;
    }
    else
    {
        fuelGauge -= CAR_CONST::FUEL_STEP;
    }
    
    if ((curSpeed+CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
    {
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }
    
    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
    if (curSpeed < CAR_CONST::BRK_STEP)
    {
        curSpeed = 0;
        return;
    }
    
    curSpeed -= CAR_CONST::BRK_STEP;
}