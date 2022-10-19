#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vertical[99999];
int horizontal[99999];

int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int max_area(w, h, stepV, stepH)
{
    vertical[stepV] = w;
    horizontal[stepH] = h;
    int Max = 0;
    for(int i = 0; i < stepH; i++)
    {
        for(int j = 0; j < stepV; j++)
        {
            int area = (vertical[j + 1] - vertical[j]) * (horizontal[i + 1] - horizontal[i]);
            Max = (area > Max) ? area : Max;
        }
    }
    return Max;
}

void getMaxArea(int w, int h, int isVertical_count, int isVertical[],int distance_count, int distance[], int* result_count)
{
    //long* result = (long *)malloc(isVertical_count * sizeof(long));
    //*result_count = isVertical_count;

    int stepV = 1;
    int stepH = 1;
    vertical[0] = 0;
    horizontal[0] = 0;


    for(int i = 0; i < isVertical_count; i++)
    {
            if (isVertical[i] == 1)
            {
                vertical[stepV] = w - distance[i];
                stepV++;
                qsort(vertical, stepV , sizeof(int), cmp);
            }
            else
            {
                horizontal[stepH] = h -distance[i];
                stepH++;
                qsort(horizontal, stepH , sizeof(int), cmp);
            }
        
        
        int x = max_area(w, h, stepV, stepH);
        printf("%i\n",x);
    }


}


int main(void){
    int w = 4;
    int h = 4;
    int isVertical[] = {0,1};
    int distance[] = {3,1};
    int isVertical_count = sizeof(isVertical) / sizeof(isVertical[0]);
    int distance_count = sizeof(distance) / sizeof(distance[0]);
    int* result_count = NULL;
    //int max_area;



     getMaxArea(w, h, isVertical_count, isVertical, distance_count, distance,result_count);

    /*for(int i = 0; i < 1 ;i++ )
    {
        printf("%li\n",result[i]);
    }*/

}
