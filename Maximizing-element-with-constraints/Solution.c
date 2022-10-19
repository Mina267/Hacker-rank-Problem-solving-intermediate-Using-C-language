#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(void){
    int n = 10;
    int maxSum = 22;
    int k = 2;
    int max_num;

    int X = maxSum / n;

    if(maxSum % n == 0)
        max_num = X;
    else
        max_num = X + 1;



    printf("%i\n",max_num);
}