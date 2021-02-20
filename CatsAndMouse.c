//https://www.hackerrank.com/challenges/cats-and-a-mouse/problem
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void catAndMouse(int a, int b, int c) {
    /*
     * Write your code here.
     */
    if(abs(a-c) < abs(b-c))
        printf("%s\n","Cat A");
    else if(abs(a-c) > abs(b-c))
        printf("%s\n","Cat B");
    else
        printf("%s\n","Mouse C");

}


int main()
{
    int q,i,a,b,c;
    
    scanf("%d",&q);
    
    for(i=0;i<q;i++){
        scanf("%d %d %d",&a,&b,&c);
        catAndMouse(a,b,c);
    }

    return 0;
}
