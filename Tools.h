#pragma once
#include <iostream>
using namespace std;

int digit(int x) // get x's precision
{
    int ans = 1;
    while ((x /= 10) != 0)
        ans++;
    return ans;
}
long long int atolli(const char* A)
{
    long long int ans = 0;
    int L = strlen(A);
    for (int i = 0; i < L; i++)
        ans = ans * 10 + (int)(A[i] - '0');
    return ans;
}
bool isCintPart(char ch)
{
    return (ch == '-' || (ch >= '0' && ch <= '9')) ? true : false;
}
int neighbor(int old) // find new capacity
{
    return old - old % MemStep + MemStep;
}