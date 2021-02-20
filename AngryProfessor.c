//https://www.hackerrank.com/challenges/angry-professor/problem
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* angryProfessor(int k, int a_size, int* a) {
    // Complete this function
    char* result = (char*) malloc(sizeof(char)*4);
    int i,count=0;
    for(i=0;i<a_size;i++){
        if(a[i]<=0)
            count++;     
        
        if(count>=k){
            sprintf(result,"%s","NO");
            return result;
        }      
    }
    

    sprintf(result,"%s","YES");
    return result;
    
}

int main() {
    int t; 
    scanf("%i", &t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        int k; 
        scanf("%i %i", &n, &k);
        int *a = malloc(sizeof(int) * n);
        for (int a_i = 0; a_i < n; a_i++) {
           scanf("%i",&a[a_i]);
        }
        int result_size;
        char* result = angryProfessor(k, n, a);
        printf("%s\n", result);
    }
    return 0;
}
