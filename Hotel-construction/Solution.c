#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int there_is_road[50][50];
int distances[50][50];

void distance(int src0, int src1, int src2, int citiesCnt,int count)
{
    count++;
    for(int i = 1; i <= citiesCnt; i++)
    {
        if(there_is_road[src2][i] == 1 && i != src1)
        {
            distances[src0][i] = count;
            distance(src0, src2, i , citiesCnt, count);
        }
    }
}


int numberOfWays(int roads_rows, int roads_columns, int roads[][2])
{
    int citiesCnt = roads_rows + 1;

    for(int i = 0; i < roads_rows; i++)
    {
        there_is_road[roads[i][0]][roads[i][1]] = 1;
        there_is_road[roads[i][1]][roads[i][0]] = 1;
    }

    for(int i = 1; i <= citiesCnt; i++)
    {
        for(int j = 1; j <= citiesCnt; j++)
        {
            if(there_is_road[i][j] == 1)
            {
                distances[i][j] = 1;
                distance(i, i, j, citiesCnt, 1);
            }
        }
    }


    int cnt = 0;
    for(int city1 = 1; city1 <= citiesCnt; city1++)
    {
        for(int city2 = city1 + 1; city2 <= citiesCnt; city2++)
        {
            for(int city3 = city2 + 1; city3 <= citiesCnt; city3++)
            {
                if(distances[city1][city2] == distances[city1][city3] && distances[city1][city2] == distances[city2][city3])
                cnt++;
            }
        }
    }
    return cnt;
}





int main(void){
    /*int roads_rows = 4;
    int roads_columns;
    int roads[4][2]={{1,2},{2,3},{3,4},{4,5} ;
    int citiesCnt = roads_rows + 1;*/
    int roads_rows = 13;
    int roads_columns = 2;
    int roads[13][2]={{9,5},{12,5},{11,9},{13,9},{1,12},{8,12},{2,11},{3,11},{14,13},{4,13},{6,1},{7,1},{10,8}};
    int cnt = numberOfWays(roads_rows, roads_columns, roads);
     printf("%i\n",cnt);
}


