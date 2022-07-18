//Created by @EGzhaodong@outlook.com
//2022 | 星期一 | 08:10:45
//Weather:sunny

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
    delete[] number;
    number = NULL;
    N = 0;
    sign = true;
    digit = 0;
    capacity = 0;
}

int neighbor(int digit)
{
    int ans = 1, i;
    if (digit == 0)
        ans = 0;
    else
        for (i = 0; i < digit; i++)
            ans *= 10;
    return ans;
}
int
Digit(int x)
{
	int ans = 1;
	while ((x /= 10) != 0)
		ans++;
	return ans;
}
int
Strlen(char* A)
{
	int ans;
	for (ans = 0; A[ans] != '\0'; ans++)
		;
	return ans;
}
char* 
Itoa(int x, char* A = NULL)
{
	int digit = Digit(x), i;
	if (A == NULL)
		char* A = new char[digit + 1];
	for (i = digit - 1; i >= 0 && A != NULL; i--)
	{
		A[i] = (char)(x % 10 + '0');
		x /= 10;
	}
	if(A!=NULL)
		A[digit] = '\0';
	return A;
}
char* 
Strcpy(char* dest, char* sour)
{
	int x = Strlen(sour);
	int i;
	for (i = 0; i < x; i++)
		dest[i] = sour[i];
	dest[i] = '\0';
	return dest;
}
istream operator>>(istream &inPut, cint &orig)
{
    string str; // I don't know the digit of input number,string can be replaced with linked list struct
    inPut >> str;
    orig.digit = str.size();
    if (str[0] == '-')
        orig.sign = false;
    else
        orig.sign = true;
    if (orig.digit < MinDigit)
        int 
