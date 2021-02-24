//https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem
#include<stdio.h>
#include<stdlib.h>


int main(){
    int *c;
    int n,k,e,i;

    scanf("%d%d", &n, &k);
    e = 100;
    i=0;    
    c = malloc(n* sizeof(int));

    for(int j = 0; j<n; j++){
        scanf("%d", &c[j]);
    }

    do{
        i = (i + k) % n;

        e--;

        if(c[i] == 1){
            e -= 2;
        }

    } while(i != 0);

    printf("%d\n",e);


}