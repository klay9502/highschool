//
//  main.cpp
//  3_17 Class
//
//  Created by 김종민 on 2015. 3. 17..
//  Copyright (c) 2015년 Jong-Min Kim. All rights reserved.
//

/*
#include <iostream>

using namespace std;

#define ID_LEN          20
#define MAX_SPD         200
#define FUEL_STEP       2
#define ACC_STEP        10
#define BRK_STEP        10

struct Car
{
    char gameID[ID_LEN];        // 소유자 ID
    int fuelGauge;              // 연료량
    int curSpeed;               // 현재속도
    
    void ShowCarState()
    {
        cout << "소유자 ID: " << gameID << endl;
        cout << "연료량: " << fuelGauge << "%" << endl;
        cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
    }
    
    void Accel()
    {
        if (fuelGauge <= 0)
        {
            return;
        }
        else
        {
            fuelGauge -= FUEL_STEP;
        }
        
        if (curSpeed + ACC_STEP >= MAX_SPD)
        {
            curSpeed = MAX_SPD;
            return;
        }
        
        curSpeed += ACC_STEP;
    }
    
    void Break()
    {
        if (curSpeed < BRK_STEP)
        {
            curSpeed = 0;
            return;
        }
        
        curSpeed -= BRK_STEP;
    }
};

int main(void)
{
    Car run99 = {"run99", 100, 0};
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();
    
    Car sped77 = {"sped77", 100, 0};
    sped77.Accel();
    sped77.Break();
    sped77.ShowCarState();
    
    return 0;
}
*/

/*
#include <iostream>

using namespace std;

class Account {
public:
    char accID[20];     // 계좌번호
    char secID[20];     // 비밀번호
    char name[20];      // 이름
    int balance;        // 잔액
    
    void Deposit(int money)
    {
        balance += money;
    }
    
    void Withdraw(int money)
    {
        balance -= money;
    }
};

int main(void)
{
    Account yoon = {
        "1234",
        "2345",
        "yoon",
        1000
    };
    
    yoon.Deposit(100);
    cout << "잔      액 :" << yoon.balance << endl;
    yoon.Withdraw(200);
    cout << "잔      액 :" << yoon.balance << endl;
    
    return 0;
}
*/

/*
#include <iostream>
#include <cstring>

using namespace std;

namespace CAR_CONST
{
    enum
    {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };
}

class Car
{
private:
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;
public:
    void InitMembers(char * ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

void Car::InitMembers(char *ID, int fuel)
{
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState()
{
    cout << "소유자ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << "%d" << endl;
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
    
    if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
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

int main(void)
{
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();
    
    return 0;
}
*/

#include <iostream>

using namespace std;

class Munja
{
private:
    char OldNumber;
    char Number;
    
public:
    void InitMember(char input)
    {
        OldNumber = input;
    }
    
    void Translate(void)
    {
        if (OldNumber >= 'A' && OldNumber <= 'Z')
        {
            Number = tolower(OldNumber);
        }
        if (OldNumber >= 'a' && OldNumber <= 'z')
        {
            Number = toupper(OldNumber);
        }
    }
    
    void ShowResult(void)
    {
        if (OldNumber >= 'A' && OldNumber <= 'Z')
        {
            cout << "대문자 " << OldNumber << "을 소문자 " << Number << "으로 변환 했습니다" << endl;
        }
        if (OldNumber >= 'a' && OldNumber <= 'z')
        {
            cout << "소문자 " << OldNumber << "을 대문자 " << Number << "으로 변환 했습니다" << endl;
        }
    }
};

int main(void)
{
    Munja str;
    char input;
    
    cout << "변환할 영문자를 입력해 주세요.: ";
    cin >> input;
    
    str.InitMember(input);
    str.Translate();
    str.ShowResult();
    
    return 0;
}