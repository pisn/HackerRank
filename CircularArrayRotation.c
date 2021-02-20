//https://www.hackerrank.com/challenges/circular-array-rotation/problem
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,k,q, query;
    int *ar;

    scanf("%d%d%d",&n, &k,&q);

    ar = malloc(n * sizeof(int));

    for(int i=0;i<n;i++){
        scanf("%d", &ar[i]);
    }

    for(int i=0;i<q;i++){
        scanf("%d", &query);
        
        //array "starts" k positions before end. k mod n because can rotate a number of times bigger than array. Every n times, array returns to start
        printf("%d\n",ar[(query + (n-(k%n))) % n]); //k mod n because can rotate a number of times bigger than array

    }

}