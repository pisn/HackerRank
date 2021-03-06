//https://www.hackerrank.com/challenges/migratory-birds/problem
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int migratoryBirds(int n, int* ar) {
    // Complete this function
    int i,maxCount = 0,maxNumber=-1;
    int *count = calloc(5,sizeof(int));
    for(i=0;i<n;i++){
        count[ar[i]-1]++;
    }
    
    for(i=0;i<5;i++){
        if(count[i] > maxCount){
            maxNumber = i;
            maxCount = count[i];
        }
    }
    
    free(count);    
    return(maxNumber+1);
}

int main() {
    int n; 
    scanf("%i", &n);
    int *ar = malloc(sizeof(int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       scanf("%i",&ar[ar_i]);
    }
    int result = migratoryBirds(n, ar);
    printf("%d\n", result);
    return 0;
}
