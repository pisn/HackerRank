//https://www.hackerrank.com/challenges/counting-valleys/problem
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int countingValleys(int n, char* s) {
    // Complete this function
    int i,height = 0,valleys=0;
    
    for(i=0;i<n;i++){
        if(s[i] == 'U')
            height++;
        else
            height--;
        
        if(s[i] == 'U' && height==0) //Just climbed to sealevel
            valleys++;
    }
    return valleys;
}

int main() {
    int n; 
    scanf("%i", &n);
    char* s = (char *)malloc(1000000 * sizeof(char));    
    scanf("%s", s);
    int result = countingValleys(n, s);
    printf("%d\n", result);
    return 0;
}
