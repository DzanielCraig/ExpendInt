#include <iostream>
#include "cint.h"
#include "../Algorithm/LinkedLists.h"
// Created by EGzhaodong@outlook.com
// 2022 | 星期四 | 16:31:41
// Weather:sunny
// we decided to use dynamic alloc and put number to right

istream&
operator>>(istream& inPut, cint& orig)
{
    long long int x = 1;
    char* num = new char[x];
    cin >> num[0];
    if (num[0] == '+' || num[0] == '-')
    {
        orig.sign = num[0];

    }
    else if (num[0] >= '0' && num[0] <= '9')
        orig.sign = '+';
    else
    {
        orig.~cint();
        return inPut;
    }

    if (orig.N >= 0)
        orig.sign = '+';
    else
        orig.sign = '-';
}