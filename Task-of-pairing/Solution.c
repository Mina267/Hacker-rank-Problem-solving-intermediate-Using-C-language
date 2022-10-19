#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int taskOfPairing(int freq_size, int freq[])
{
    int pair_count = 0;
    int extra_pair = 0;

    for(int i = 0; i < freq_size; i++)
    {
        if(freq[i] % 2 == 0)
        {
            pair_count += freq[i] / 2;
        }
        else
        {
            pair_count += freq[i] / 2;
            extra_pair++;
        }
    }

    return (pair_count + extra_pair / 2);
}


int main(void){
    //int freq[] = {6, 5, 3};
    int freq[] = {5, 6, 2};
    int freq_size = 3;

    int pair_count = taskOfPairing(freq_size, freq);

    printf("%i\n",pair_count);
}