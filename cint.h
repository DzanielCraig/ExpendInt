// Created by EGzhaodong@outlook.com
// 2022 | 星期二 | 15:11:26
// Weather:sunny

#include <iostream>
#define MinPrec 18
#define MemStep 100
using namespace std;

// now we want to expend int,which can slove number that bigger than long long int

// request:
// 1.as big as computer's memory
// 2.can slove positive ,negative,decimal number,such as'+123...', '-123...', '123.456...'
// 3.use long long int to operator when precision is smaller than MinPrec,not include decimal

// new idea :
// 1.the smallest cell is unsigned int
// 2.for now,one cell on behalf of one precision
// 3.put number to the right
// 4.dynamic alloc

class cint
{
private:
    unsigned int *number;
    long long int N;

    char sign;
    int afterPoint; // after decimal point
    int precision;
    int capacity;

protected:
    void Modify(int max);
    void ReAlloc(int maxCapacity);

public:
    cint();
    ~cint();
    cint(const cint &item);

    friend istream &operator>>(istream &inPut, cint &orig);
    friend ostream &operator<<(ostream &outPut, const cint &orig);

    cint operator+(const cint &item);
};

inline cint::cint() // initalize with both none
{
    number = NULL;
    N = 0;
    sign = '+';
    precision = 0;
    capacity = 0;
}

inline cint::~cint()
{
    delete[] number;
    number = NULL;
    N = 0;
    sign = '+';
    precision = 0;
    capacity = 0;
}

// Created by EGzhaodong@outlook.com
// 2022 | 星期六 | 18:35:43
// Weather:sunny
inline cint::cint(const cint &item)
{
    N = item.N;
    sign = item.sign;
    precision = item.precision;
    capacity = item.capacity;

    if (item.number == NULL)
        number = item.number;
    else
    {
        number = new unsigned int[capacity]{0};
        for (int i = capacity - 1; i > capacity - precision - 1; i--)
            number[i] = item.number[i];
    }
}
void cint::ReAlloc(int maxCapacity) // alloc a new(always bigger) memory block for number
{
    unsigned int *Tmp = new unsigned int[maxCapacity];
    int i = maxCapacity - 1, j = this->capacity - 1, end = maxCapacity - this->precision;
    for (; i >= end; i--, j--)
        Tmp[i] = this->number[j];
    delete[] this->number;
    this->number = Tmp;
}
int neighbor(int old) // find new capacity
{
    return old - old % MemStep + MemStep;
}

int Digit(int x) // get x's precision
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
    int precision = Digit(x), i;
    if (A == NULL)
        char *A = new char[precision + 1];
    for (i = precision - 1; i >= 0 && A != NULL; i--)
    {
        A[i] = (char)(x % 10 + '0');
        x /= 10;
    }
    if (A != NULL)
        A[precision] = '\0';
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
    for (int i = 0; i < orig.precision; i++)
        outPut << orig.number[i];

    return outPut;
}

// Created by EGzhaodong@outlook.com
// 2022 | 星期四 | 09:21:11
// Weather:sunny
cint cint::operator+(const cint &item)
{
    int maxPrec = precision > item.precision ? precision + 2 : item.precision + 2;
    cint ans(*this);
    if (ans.capacity < maxPrec)
        ReAlloc(neighbor(maxPrec));
    int i =
        for (int i = capacity - 1; i < maxPrec; i++)
    {
        }
}