//
//  main.cpp
//  3_19
//
//  Created by 김종민 on 2015. 3. 19..
//  Copyright (c) 2015년 Jong-Min Kim. All rights reserved.
//

/*
#include "Car.h"

int main(void)
{
    Car run99;
    
    run99.InitMember("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();
    
    return 0;
}
*/

/*
#include <iostream>
using namespace std;

class FruitSeller
{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;
public:
    void InitMembers(int price, int num, int money)
    {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }
    
    int SaleApples(int money)
    {
        int num = money/APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num;
    }
    
    void ShowSalesResult(void)
    {
        cout << "남은 사과: " << numOfApples << endl;
        cout << "판매 수익: " << myMoney << endl << endl;
    }
};

class FruitBuyer
{
private:
    int myMoney;
    int numOfApples;
    
public:
    void InitMumbers(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }
    
    void BuyApples(FruitSeller &seller, int money)
    {
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }
    
    void ShowBuyResult(void)
    {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numOfApples << endl << endl;
    }
};

int main(void)
{
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);
    
    FruitBuyer buyer;
    buyer.InitMumbers(5000);
    buyer.BuyApples(seller, 2000);      // 과일의 구매!
    
    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesResult();
    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();
    
    return 0;
}
*/