#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int dp[200001][2] = {0};

int minOperations(int arr_count, int* arr, int threshold, int d)
{

    qsort(arr, arr_count, sizeof(int), cmp);
    int min = INT_MAX;

    for(int i = 0; i < arr_count; i++)
    {
        int steps = 0;
        while(1)
        {
            int x = arr[i];
            dp[x][0] += 1;
            dp[x][1] += steps;
            if(dp[x][0] >= threshold)
                min = (min <= dp[x][1]) ? min : dp[x][1];
            if( x == 0)
                break;

            arr[i] /= d;
            steps++;
        }
    }

    return min;
}


int main(void){
    int arr[] = {64, 30, 25, 33};
    int arr_count = sizeof(arr) / sizeof(arr[0]);
    int threshold = 2;
    int d = 2;
    int x= minOperations(arr_count, arr,threshold, d);

     printf("%i\n",x);


}

