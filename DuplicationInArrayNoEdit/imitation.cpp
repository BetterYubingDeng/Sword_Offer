//
// Created by 邓宇兵 on 2019-07-19.
//
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

int countRange(const int* numbers,int length,int start, int end)
{
    if(numbers == NULL || length <= 0)
        return 0;
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if(numbers[i] <= end && numbers[i] >= start)
        {
            ++count;
        }
    }
    return count;
}

int getDuplicatoin(const int* numbers,int length)
{
    if(numbers == NULL || length <= 0)
        return -1;
    int start = 1;
    int end = length - 1;
    while(start <= end)
    {
        int middle = ((end - start) >> 1) + start;
        int count = countRange(numbers,length,start,middle);
        if(end == start)
        {
            if(count > 1)
            {
                return start;
            } else{
                break;
            }
        }
        if(count > (middle - start) + 1)
        {
            middle = end;
        } else{
            start = middle + 1;
        }
    }

    return -1;
}
