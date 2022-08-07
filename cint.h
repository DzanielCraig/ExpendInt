#pragma once
#include <iostream>
#define MinPrec 18
#define MemStep 100
#define CaySysm 10
using namespace std;

class Cint
{
protected:
    unsigned short int* number;
    long long int N;

    int sign;
    int precision;
    int capacity;

    void Modify();
    int ReAlloc(int maxCapacity);
public:
    Cint();
    ~Cint();
    Cint(const Cint& item);

    friend istream& operator>>(istream& inPut, Cint& orig);
    friend ostream& operator<<(ostream& outPut, const Cint& orig);

};

inline Cint::Cint() // initalize with both none
{
    number = NULL;
    N = 0;
    sign = 1;
    precision = 0;
    capacity = 0;
}

inline Cint::~Cint()
{
    delete[] number;
    number = NULL;
    N = 0;
    sign = 1;
    precision = 0;
    capacity = 0;
}

inline Cint::Cint(const Cint& item)
{
    N = item.N;
    sign = item.sign;
    precision = item.precision;
    capacity = item.capacity;

    if (item.number == NULL)
        number = item.number;
    else
    {
        number = new unsigned short int[capacity] {0};
        for (int i = capacity - 1; i > capacity - precision - 1; i--)
            number[i] = item.number[i];
    }
}







