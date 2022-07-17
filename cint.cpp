// Created by @EGzhaodong@outlook.com
// 2022 | 星期天 | 18:56:16

#include <iostream>
using namespace std;

class cint
{
private:
    unsigned int *number;
    long long int N;
public:
    bool sign;
    int digit;
    int capacity;
public:
    cint();
    ~cint();
};

cint::cint()//initalize with both none
{
    number=NULL;
    N=0;
    sign=true;
    digit=0;
    capacity=0;
}

cint::~cint()
{
    delete[]number;
    number=NULL;
    N=0;
    sign=true;
    digit=0;
    capacity=0;
}
