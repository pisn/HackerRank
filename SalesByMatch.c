//https://www.hackerrank.com/challenges/sock-merchant/problem
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int sockMerchant(int n, int* ar) {
    // Complete this function
    int i,count = 0;
    int *socks = calloc(101,sizeof(int));
    
    for(i=0;i<n;i++){
        socks[ar[i]]++;
    }
    
    for(i=0;i<=100;i++){
        if(socks[i]>0)
            count+=(socks[i]/2); //Integer division truncates 
    }  
    
    free(socks);
    return count;
}

int main() {
    int n; 
    scanf("%i", &n);
    int *ar = malloc(sizeof(int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       scanf("%i",&ar[ar_i]);
    }
    int result = sockMerchant(n, ar);
    printf("%d\n", result);
    return 0;
}
