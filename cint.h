// Created by EGzhaodong@outlook.com
// 2022 | 星期二 | 15:11:26
// Weather:sunny

#include <iostream>
#include "../Algorithm/LinkedLists.h"
#define MinDigit 18
using namespace std;

// now we want to expend int,which can slove number that bigger than long long int

// new idea:
// 1.replace unsigned int with char
// 2.replace signal digit with double、treble...

// now we have DataStruct like cint,and operator like:
class cint
{
private:
    unsigned int *number;
    long long int N;

    char sign;
    int digit;
    int capacity;

public:
    cint();
    ~cint();
    cint(const cint &item);

    friend istream &operator>>(istream &inPut, cint &orig);
    friend ostream &operator<<(ostream &outPut, const cint &orig);

    cint operator+(const cint &item);
    void Modify(int max);
};

inline cint::cint() // initalize with both none
{
    number = NULL;
    N = 0;
    sign = '+';
    digit = 0;
    capacity = 0;
}

inline cint::~cint()
{
    delete[] number;
    number = NULL;
    N = 0;
    sign = '+';
    digit = 0;
    capacity = 0;
}

inline cint::cint(const cint &item)
{
    N = item.N;
    sign = item.sign;
    digit = item.digit;
    capacity = item.capacity;

    if (item.number == NULL)
        number = item.number;
    else
    {
        number = new unsigned int[capacity]{0};
        for (int i = 0; i < digit; i++)
            number[i] = item.number[i];
    }
}
int neighbor(int digit) // find new capacity
{
    int ans = 1, i;
    if (digit == 0)
        ans = 0;
    else
        for (i = 0; i < digit; i++)
            ans *= 10;
    return ans;
}

int Digit(int x) // get x's digit
{
    int ans = 1;
    while ((x /= 10) != 0)
        ans++;
    return ans;
}

int Strlen(char *A) // get A's length
{
    int ans;
    for (ans = 0; A[ans] != '\0'; ans++)
        ;
    return ans;
}

char *
Itoa(int x, char *A = NULL) // let x follow *A
{
    int digit = Digit(x), i;
    if (A == NULL)
        char *A = new char[digit + 1];
    for (i = digit - 1; i >= 0 && A != NULL; i--)
    {
        A[i] = (char)(x % 10 + '0');
        x /= 10;
    }
    if (A != NULL)
        A[digit] = '\0';
    return A;
}

char *
Strcpy(char *dest, char *sour) // just strcpy
{
    int x = Strlen(sour);
    int i;
    for (i = 0; i < x; i++)
        dest[i] = sour[i];
    dest[i] = '\0';
    return dest;
}

bool IsCintPart(char ch)
{
    return (ch == '-' || (ch >= '0' && ch <= '9')) ? true : false;
}

// ostream &operator<<(ostream &outPut, const cint &orig);
// Created by EGzhaodong@outlook.com
// 2022 | 星期一 | 11:40:55
// Weather:sunny
ostream &
operator<<(ostream &outPut, const cint &orig)
{
    for (int i = 0; i < orig.digit; i++)
        outPut << orig.number[i];

    return outPut;
}

// Created by EGzhaodong@outlook.com
// 2022 | 星期四 | 09:20:17
// Weather:sunny
void cint::Modify(int max = 0) // let number array become the right format
{
    if (max == 0)
        max = capacity;
    if (max > capacity)
    {
        unsigned int *T = number;
        number = new unsigned int[neighbor(max)]{0};
        for (int i = 0; i < digit; i++)
            number[i] = T[i];
        delete[] T;
        N = 0;
    }

    int i, x = max - digit;
    for (i = max - 1; i >= x; i--) // move array to right side
    {
        number[i] = number[i - x];
        number[i - x] = 0;
    }

    for (i = max - 1; i > 0; i--) // carry digit
        if (number[i] > 9)
        {
            number[i - 1] += number[i] / 10;
            number[i] = number[i] % 10;
        }
    for (x = 0; x < max; x++) // find first digit
        if (number[x] != 0)
            break;
    for (i = x; i < max; i++) // move array to left side
        number[i - x] = number[i];
    digit = max - x;
}

// Created by EGzhaodong@outlook.com
// 2022 | 星期四 | 09:21:11
// Weather:sunny
cint cint::operator+(const cint &item)
{
    cint ans(*this);
    int maxDigit = digit > item.digit ? digit : item.digit;
    for (int i = 0; i < maxDigit; i++)
    {
    }
}