#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int maxPairs(int skillLevel_count, int skillLevel[], int minDiff)
{
    qsort(skillLevel, skillLevel_count, sizeof(int), cmp);

    int iteration = skillLevel_count / 2 - 1;
    int last_index = skillLevel_count - 1;
    int count = 0;

    while(iteration  >= 0)
    {
        if(skillLevel[last_index] - skillLevel[iteration] >= minDiff)
        {
            count++;
            last_index--;
        }
        iteration--;
    }
    return count;
}



int main(void){

    int skillLevel_count = 11;
    //int skillLevel[] = {3, 4, 5 ,2, 1, 1};
    int skillLevel[] = {25107191,123232501,151290765,183012194,473251358,579542802,689345248,709552565,803612259,862726097,994391793,440987423};
    int minDiff = 440987423;

    int count = maxPairs(skillLevel_count, skillLevel, minDiff);

    printf("%i\n",count);

}

