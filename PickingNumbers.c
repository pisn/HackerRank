//https://www.hackerrank.com/challenges/picking-numbers/problem
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int pickingNumbers(int a_size, int* a) {
    // Complete this function
    int *c,i,m=0;
    
    c = (int*)calloc(101,sizeof(int));
    
    for(i=0;i<a_size;i++){
        c[a[i]]++;
    }
    
    for(i=0;i<a_size-1;i++){
        if(c[i]+c[i+1]>m)
            m = c[i]+c[i+1];
    }
    
    free(c);
    return m;
}

int main() {
    int n; 
    scanf("%i", &n);
    int *a = malloc(sizeof(int) * n);
    for (int a_i = 0; a_i < n; a_i++) {
       scanf("%i",&a[a_i]);
    }
    int result = pickingNumbers(n, a);
    printf("%d\n", result);
    return 0;
}
