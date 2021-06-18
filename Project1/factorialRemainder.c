/*
 * @Author: your name
 * @Date: 2021-06-15 16:07:34
 * @LastEditTime: 2021-06-17 15:04:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \factorialRemainder\factorialRemainder.c
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int n);
unsigned int length(int num);
int Get_Mod(int divisor[], int num, int dividend);

int factorialRemainder(int n)
{

    static int i;
    int temp = n, temp1 = 0;
    static unsigned long long mutiple_num = 1;

    while (n != 1)
    {
        if (temp < 20)
        {
            mutiple_num = 1;
            for (i = 1; i < n; i++)
            {
                mutiple_num = mutiple_num * i;
            }
            if ((mutiple_num % n) == (n - 1))
            {
                return i;
            }
        }
        else
        {
            temp1 = factorial(n);
            if (temp1 == n - 1)
            {
                return n;
            }
        }
        n -= 1;
    }
    return 0;
}
int factorial(int n)
{
    int temp, bit_num = 1, carry_bit = 0;
    int cache_arry[500000];

    cache_arry[0] = 1;
    for (int i = 2; i < n; i++)
    {
        carry_bit = 0;
        for (int j = 1; j <= bit_num; j++)
        {
            temp = cache_arry[j - 1] * i + carry_bit;
            cache_arry[j - 1] = temp % 10;
            carry_bit = temp / 10;
        }
        while (carry_bit)
        {
            bit_num++;
            cache_arry[bit_num - 1] = carry_bit % 10;
            carry_bit = carry_bit / 10;
        }
    }
    int temp1;
    for (int i = 0; i <= (bit_num - 1) / 2; i++)
    {
        temp1 = cache_arry[i];
        cache_arry[i] = cache_arry[bit_num - i - 1];
        cache_arry[bit_num - i - 1] = temp1;
    }
    // printf("n!=");
    // for (int j = 0; j <= bit_num - 1; j++)
    //     printf("%d", cache_arry[j]);
    // printf("\n");

    return Get_Mod(cache_arry, bit_num, n);
}
int Get_Mod(int divisor[], int num, int dividend)
{
    int temp = 0, temp1 = 0, temp2 = 0;

    for (int i = 0; i < length(dividend); i++)
    {
        temp += divisor[i] * (int)(pow(10, (length(dividend)) - i - 1));
    }
    //printf("value2=%d\n\r", temp);

    for (int j = length(dividend); j < num; j++)
    {
        if (temp == 0)
        {
            temp = divisor[j] % dividend;
        }
        else
        {
            temp = ((temp % dividend) * 10 + divisor[j]) % dividend;
        }
        //printf("value3=%d\n\r", temp);
    }

    return temp;
}
unsigned int length(int num)
{
    static int i;
    int temp = num;
    if (num != 0)
    {
        for (i = 1; i <= 7; i++)
        {
            if ((temp /= 10) == 0)
                return i;
        }
    }
    return 0;
}

int main()
{
    int i = 0;
    printf("please input: ");
    scanf("%d", &i);
    printf("n=%d\n\r", factorialRemainder(i));
}
