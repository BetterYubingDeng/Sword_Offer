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
        if(count > (middle - start + 1))
        {
            end = middle;
        } else{
            start = middle + 1;
        }
    }
    return -1;
}

///测试代码
void test(char* testName,int* numbers,int numlen,int* duplication,int duplength)
{
    printf("%s:",testName);
    int dupTemp = getDuplicatoin(numbers,numlen);
    for (int i = 0; i < duplength; ++i) {
        if(dupTemp == duplication[i]) {
            printf("Passed.\n");
            return;
        }
    }
    printf("Failed.\n");
}

///测试案例

///1.多个重复数字
void testOne()
{
    int numbers[] = {2,3,1,4,5,2,3,2};
    int dup[] = {2,3};
    char* test01 = "testOne";
    test(test01,numbers, sizeof(numbers)/ sizeof(int),dup, sizeof(dup)/ sizeof(int));
}

int main()
{
    testOne();
    return 0;
}
