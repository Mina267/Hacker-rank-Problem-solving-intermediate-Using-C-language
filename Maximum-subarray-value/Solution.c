#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))



long maxSubarrayValue(int n, int arr[])
{
    for(int i = 1; i < n; i += 2)
    {
        arr[i] = 0 - arr[i];
    }

    int currmin = arr[0];
    int minSofar = arr[0];
    int currmax = arr[0];
    int maxSofar = arr[0];

    for(int i = 1; i < n; i++)
    {
        currmax = max(arr[i], currmax + arr[i]);
        maxSofar = max(maxSofar, currmax);
        currmin = min(arr[i], currmin + arr[i]);
        minSofar = min(minSofar, currmin);
    }
    long MAX = (abs(maxSofar) > abs(minSofar)) ? abs(maxSofar) : abs(minSofar);

    return MAX * MAX;

}
int main(void){

    int n = 6;
    int arr[6] ={3, -1, -1, -1, 5, 1};

         long MAX = maxSubarrayValue(n, arr);


    printf("%li\n", MAX);

}
