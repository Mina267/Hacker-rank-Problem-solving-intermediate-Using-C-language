#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int renameFile(char* newName,char* oldName)
{
    int count = 0;
    int old_lenght = strlen(oldName);

    for(int i = 0; i < old_lenght - 2; i++)
    {
        if(newName[0] == oldName[i])
        {
            for(int j = i + 1; j < old_lenght - 1; j++)
            {
                if(newName[1] == oldName[j])
                {
                    for(int k = j + 1; k < old_lenght; k++)
                    {
                        if(newName[2] == oldName[k])
                        {
                            count++;
                        }
                    }
                }
            }
        }
    }

    return count;
}


int main(void){
    int arr[] = {10, 7, 2, 8, 3};
    char* new_name = "rrk";
    char* old_name= "eispnddxtnfqalswxsmksfooiwxynamdjxnsmkiewkwdpzjpkibcbbmzbiwpmjczcehtczqjzlkgyvszpuuvetdfluuhxpeopuxmdylaysttenjmcedcumoeeicjtxkkvxcxjowrcvlttsqhwkbbmigtqlovjgviyzgcqjvpvotwucsetidicyhtcmajphxyyooeovuxvuploklpbovqdwdypbxgajuqwadgeedjkgurhsxdvylmyfjqlwzldrouylqobsgemwdoibqvcyedfvqopfhkqmhusxqacoogjxcoxbfzlwcxfvqaavfegkcirqqgdyhljmaqzqifuaoubukypavebvdujgsulahkprfpnzqaqgvfdxwtqflceilpmszizfwbonxplcyqittpkpbcfsesgfbiqnipolefrelphjthqrzsphbnumgrifmwiztfuhqibgaxdvysyvgxlspminykbyumepubrxuoavyovdbielzdobgqcjznjbexalkghywioxzbvxzfcshcozmefwcrvyibjdfqvqmhxdpccjodlgvkplrfdedpzoprfeechwszhvcdooejlchcwcektfrdmowhsueavbrawmihzsnfhrafbqeawdixznppfwieaivtmpqzqtsvnvwjmgvhuesssaxgmoywdgvwiouzuqdebijcqycftaftuwtgxavemciuqmxenprpmyzrexshnvtesstwhytmatxbuzxpstpygfxphpfckjdbfbximeeswyndfhomcnwjtfruvzwbhlzbvebyeucepgcdpmghcibfxg";

    int count;

    count = renameFile(new_name, old_name);
    printf("%i\n",count);
}