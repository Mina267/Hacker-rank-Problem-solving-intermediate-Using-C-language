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
    int arr[] = {10, 7, 2, 8, 3};
    int arr_count = 5;
    int count = 0;
    for(int i = 0; i < arr_count - 1; i++)
    {
        for(int j = i + 1; j < arr_count; j++)
        {
            int x = arr[i] & arr[j];
            if(x % 2 == 0 && x != 0)
            {
                count++;
            }
        }
    }

    printf("%i\n",count);
}