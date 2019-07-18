//
// Created by 邓宇兵 on 2019-07-17.
//
#include <cstdio>
//判断是否为正确输入为正确输入时候则判断是否有重复数字
bool ifDuplicate(int numbers[],int length,int *duplicate)
{
    if(numbers == nullptr || length == 0)
        return false;
    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }
    for (int i = 0; i < length; ++i)
    {
        while(numbers[i] != i)
        {
           if(numbers[i] == numbers[numbers[i]])
           {
               *duplicate = numbers[i];
               return true;
           }
           int temp;
           temp = numbers[i];
           numbers[i] = numbers[temp];
           numbers[temp] = temp;
        }
    }
    return false;
}

//========测试代码==========
bool contains(int array[], int length, int number)
{
    for (int i = 0; i < length; ++i)
    {
        if(array[i] == number)
        {
            return true;
        }
    }
    return false;
}


void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
   printf("%s:",testName) ;
   bool validInput;
   int duplication;
   validInput = ifDuplicate(numbers,lengthNumbers,&duplication);
   if(validArgument == validInput) {
       if (validInput) {
           if (contains(expected, expectedExpected, duplication)) {
               printf("Passed.\n");
           } else {
               printf("Failed.\n");
           }
       } else {
           printf("Passed.Invalid input.\n");
       }
   }else{
       printf("Failed.Invalid test example.\n");
   }
}
int main()
{
    return 0;
}