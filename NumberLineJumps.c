//https://www.hackerrank.com/challenges/kangaroo/problem
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* kangaroo(int x1, int v1, int x2, int v2) {
    // Complete this function
    
    /*Only if exists r such that:
      r*v1 + x1 = r*v2 + x2
      r(v1-v2) = x2-x1
       r = (x2-x1)/(v1-v2) , r € Z
       
       if x2 > x1, then v1 must be != v2 (care with zero division)*/    
    
    if((v1-v2) > 0 && (x2-x1) % (v1-v2) == 0){ 
        return "YES";
    }
    else{
        return "NO";
    }
}

int main() {
    int x1; 
    int v1; 
    int x2; 
    int v2; 
    scanf("%i %i %i %i", &x1, &v1, &x2, &v2);
    int result_size;
    char* result = kangaroo(x1, v1, x2, v2);
    printf("%s\n", result);
    return 0;
}
