//https://www.hackerrank.com/challenges/day-of-the-programmer/problem
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int daysInFebruary(int year){
    if(year < 1918){
        if(year%4 == 0)
            return 29;
        else 
            return 28;    
    }
    else if (year == 1918){
        return 15;
    }
    else {
        if(year % 400 == 0 || (year%4 == 0 && year%100 > 0)) {
            return 29;
        }
        else
            return 28;
    }      
    
}

char* solve(int year){
    // Complete this function
    int daysInMonth[12] = {31,daysInFebruary(year),31,30,31,30,31,31,30,31,30,31};
    int count=0,i;
    int day, month;
    
    for(i=0;count<256;i++){
        if(count+daysInMonth[i] > 256){
            day = 256 - count;
            break;
        }        
        count += daysInMonth[i];
    }
    char *ret = malloc(11*sizeof(char));
    sprintf(ret,"%02d.%02d.%d",day,i+1,year);
    return ret;
}

int main() {
    int year; 
    scanf("%d", &year);
    int result_size;
    char* result = solve(year);
    printf("%s\n", result);
    free(result);
    return 0;
}
