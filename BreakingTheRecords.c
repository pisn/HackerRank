//https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,i;
    int *score;        
    
    scanf("%d",&n);
    
    score = malloc(n*sizeof(int));
    
    for(i = 0;i<n;i++){
        scanf(" %d",&score[i]);
    }
    
    int maxScore = score[0], minScore = score[0], maxRecords = 0, minRecords = 0;
    
    for (i = 1; i<n; i++) {
        if(score[i] > maxScore){
            maxScore = score[i];
            maxRecords++;
        }
        if (score[i] < minScore){
            minScore = score[i];
            minRecords++;
        }
    }   
    printf("%d %d",maxRecords,minRecords);
    
    return 0;
}
