#include "Cint.h"
#include "Tools.h"
ostream&
operator<<(ostream& outPut, const Cint& orig)
{
    if (orig.number == NULL)
        cout << orig.N * orig.sign;
    else
    {
        if (orig.sign == -1)
            cout << '-';
        for (int i = orig.capacity-orig.precision; i < orig.capacity; i++)
            outPut << orig.number[i];
    }

    return outPut;
}
istream&
operator>>(istream& inPut, Cint& orig)
{
    string str;
    int flag = 0;
    char sign;

    cin >> sign;
    if (sign >= '0' && sign <= '9')
    {
        flag = 1;
        orig.sign = 1;
    }
    else if (sign == '+' )
        orig.sign = 1;
    else if (sign == '-')
        orig.sign == -1;
    else
        return inPut;

    cin >> str;
    if (flag == 1)
        str = sign + str;
        
    int i, j;
    orig.precision = i = str.length();
    if (orig.precision > MinPrec)
    {
        orig.capacity = j = orig.ReAlloc(i--);
        for (--j; i >= 0; i--, j--)
            orig.number[j] = (int)(str[i]-'0');
    }
    else
        orig.N = atolli(str.c_str()) * orig.sign;

    return inPut;
}
void Cint::Modify() // right format
{
    int i;
    for (i = 0; i < capacity - precision; i++)
        number[i] = 0;
    for (i = this->capacity - 1; i > 0; i--)
    {
        number[i - 1] += number[i] / CaySysm;
        number[i] = number[i] % CaySysm;
    }
    for (i = 0; i < capacity; i++)
        if (number[i] != 0)
            break;
    precision = capacity - i;
}
int Cint::ReAlloc(int maxCapacity) // alloc a new(always bigger) memory block for number
{
    int ans = neighbor(maxCapacity);
    unsigned short int* Tmp = new unsigned short int[ans]{0};

    if (number != NULL)
    {
        int i = maxCapacity - 1, j = this->capacity - 1, end = maxCapacity - this->precision;
        for (; i >= end; i--, j--)
            Tmp[i] = this->number[j];
        delete[] this->number;
    }
    this->number = Tmp;

    return ans;
}