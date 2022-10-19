#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sortedSum(int a_count, int a[])
{
    long long M = 1e9 + 7;
    int tmp ;
    int sum = 0;

    for(int i = 0; i < a_count; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == (i - 1) && a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
            sum += (a[j] * (j + 1) * 1ll) % M;
        }
    }
    return sum;
}


int main(void){

    int a[] = {9, 5, 8};
    int a_count = 3;

    int sum = sortedSum(a_count, a);

    printf("%i\n", sum);
}






int sortedSum(int a_count, int* a) {
    long long M = 1e9 + 7;
    int tmp ;
    int sum = 0;

    for(int i = 0; i < a_count; i++)
    {
        int j = i;
         while(j > 0 && a[j - 1] > a[j]) 
         {
            tmp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = tmp;
            j--;
         }
        for(int j = 0; j <= i; j++)
        {
            sum = (sum + a[j] * (j + 1) * 1ll) % M;
        }
    }
    return sum;

}
