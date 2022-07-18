#pragma once
#include <iostream>
#define MinDigit 18
/*-------------------------------------------------------------------
* signal digit
* both long long int and cint
* ------------------------------------------------------------------

* ------------------------------------------------------------------
have:
1.(cint)*(int)
2.>>(cint)
3.<<(cint)
4.(cint)=(cint)

--------------------------------------------------------------------*/
int Digit(int x)
{
	int ans = 1;
	while ((x /= 10) != 0)
		ans++;
	return ans;
}
class cint
{
public:
	unsigned int* number;
	long long int N;
public:
	int digit;
	int capacity;
public:
	friend std::istream& operator >>(std::istream& inPut, cint& orig);
	friend std::ostream& operator <<(std::ostream& outPut, cint& orig);

	cint() { N = digit = capacity = 0; number = NULL; };					//无参构造函数
	cint(const cint& orig);													//拷贝构造函数

	~cint() { delete[]number; number = NULL; digit = capacity = 0; };

	cint operator =(const cint& orig);
	cint operator =(const int& orig);
	cint operator * (int x);
public:
	void modify(cint& orig, int max = MinDigit);//if max digit of modify is clear,
												//then this parameter can reduce time complexity
};
cint::cint(const cint& orig)
{
	N = orig.N;
	digit = orig.digit;
	capacity = orig.capacity;
	if (capacity != 0)
	{
		number = new int[capacity] {0};
		for (int i = 0; i < digit; i++)
			number[i] = orig.number[i];
	}
	else
		number = NULL;
}
cint
cint::operator =(const cint& orig)
{
	N = orig.N;
	digit = orig.digit;
	if (capacity >= orig.capacity)

		if (capacity != 0)

			for (int i = 0; i < digit; i++)
				number[i] = orig.number[i];
	return *this;
}
//cint
cint
cint::operator =(const int& orig)
{
	digit = Digit(orig);
	if (digit > capacity)
		exit(0);

	for (int i = 0; i < capacity; i++)
		number[i] = 0;
	number[0] = orig;

	modify(*this, digit);
	return *this;
}
cint
cint::operator * (int x)
{
	cint* Tmp = new cint;

	for (int i = 0; i < digit; i++)
		Tmp->number[i] = this->number[i] * x;

	Tmp->digit = digit;
	modify(*Tmp, digit + Digit(x));

	if (Tmp->digit > Tmp->capacity)
		exit(0);
	return *Tmp;
}
std::istream& operator >>(std::istream& inPut, cint& orig)
{
	char* number = new char[orig.capacity + 1];
	inPut >> number;

	int cnt = strlen(number);
	if (cnt > orig.capacity)
		exit(0);
	else
		orig.digit = cnt;

	for (int i = 0; i < orig.digit; i++)
		orig.number[i] = (int)(number[i] - '0');

	return inPut;
};
std::ostream& operator <<(std::ostream& outPut, cint& orig)
{
	for (int i = 0; i < orig.digit; i++)
		outPut << orig.number[i];
	return outPut;
}
void
cint::modify(cint& orig, int max)
{
	if (max > orig.capacity)
		exit(0);

	int i, x = max - orig.digit;
	for (i = max - 1; i >= x; i--)
	{
		orig.number[i] = orig.number[i - x];
		orig.number[i - x] = 0;
	}
	for (i = max - 1; i >= 0; i--)
		if (orig.number[i] > 9)
		{
			orig.number[i - 1] += orig.number[i] / 10;
			orig.number[i] = orig.number[i] % 10;
		}
	for (x = 0; x < max; x++)
		if (orig.number[x] != 0)
			break;
	for (i = x; i < max; i++)
		orig.number[i - x] = orig.number[i];
	orig.digit = max - x;
}


