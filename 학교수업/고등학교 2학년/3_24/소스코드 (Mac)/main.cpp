//
//  main.cpp
//  3_24
//
//  Created by 김종민 on 2015. 3. 24..
//  Copyright (c) 2015년 Jong-Min Kim. All rights reserved.
//

/*
#include <iostream>
#include <string.h>

using namespace std;

class MyString
{
private:
    enum
    {
        LEN = 1024
    };
    char string[LEN];
public:
    void Init(char *str);
    int  GetLength(void);
    char* GetString(void);
    void SetUpper(void);
};

void MyString::Init(char *str)
{
    strcpy(string, str);
}

int MyString::GetLength(void)
{
    int count = 0;
    
    while (!string[count] == '\0')
    {
        count++;
    }
    
    return count;
}

char* MyString::GetString(void)
{
    return string;
}

void MyString::SetUpper(void)
{
    int count = 0;
    
    while (!string[count] == '\0')
    {
        string[count] = toupper(string[count]);
        count++;
    }
}

int main(void)
{
    MyString s1;
    
    s1.Init("Happy Birthday");
    cout << "문자열의 길이는 [" << s1.GetLength() << "] 입니다." << endl;
    cout << "저장 된 문자열은 [" << s1.GetString() << "] 입니다." << endl;
    s1.SetUpper();
    cout << "대문자로 변경 된 문자열은 [" << s1.GetString() << "] 입니다." << endl;
    
    char buf[80];
    cout << endl << "문자열 입력: ";
    cin >> buf;
    
    MyString s2;
    
    s2.Init(buf);
    cout << "입력된 문자열의 길이는 [" << s2.GetLength() << "] 입니다." << endl;
    cout << "입력된 문자열은 [" << s2.GetString() << "] 입니다." << endl;
    
    return 0;
}
*/

#include <iostream>

using namespace std;

class AAA
{
private:
    int i, j;
public:
    AAA()
    {
        cout << "생성자 호출" << endl;
        i = 10, j = 20;
    }
    void ShowData()
    {
        cout << i << ' ' << j << endl;
    }
};

int main(void)
{
    AAA aaa;
    aaa.ShowData();
    
    return 0;
}