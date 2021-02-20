//https://www.hackerrank.com/challenges/bon-appetit/problem
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k,i,b,paid,sumTotal=0, fairBill=0;
    scanf("%d %d",&n,&k);
    
    for(i=0; i<n; i++){
        scanf("%d",&b);
        sumTotal += b;
        
        if(i != k)
            fairBill += b;            
    }
    fairBill /=2;
    sumTotal /=2;
    
    scanf("%d",&paid);
    
    if(paid - fairBill == 0)
        printf("Bon Appetit");
    else
        printf("%d",paid-fairBill);
    
    return 0;
}
