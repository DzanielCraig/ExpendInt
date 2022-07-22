#include <iostream>
#include "cint.h"
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
        for (int i = 0; i < precision; i++)
            number[i] = T[i];
        delete[] T;
        N = 0;
    }

    int i, x = max - precision;
    for (i = max - 1; i >= x; i--) // move array to right side
    {
        number[i] = number[i - x];
        number[i - x] = 0;
    }

    for (i = max - 1; i > 0; i--) // carry precision
        if (number[i] > 9)
        {
            number[i - 1] += number[i] / 10;
            number[i] = number[i] % 10;
        }
    for (x = 0; x < max; x++) // find first precision
        if (number[x] != 0)
            break;
    for (i = x; i < max; i++) // move array to left side
        number[i - x] = number[i];
    precision = max - x;
}