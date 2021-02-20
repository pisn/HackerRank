#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, *p, *r,i;

    scanf("%d", &n);
    
    p = malloc((n+1)*sizeof(int));
    r = malloc((n+1)*sizeof(int));

    for(i =1; i<= n; i++){
        scanf("%d", &p[i]);        
    }

    for(i = 1; i<=n; i++){
        r[p[i]] = i;        
    }

    for(i = 1; i<=n; i++){
        printf("%d\n", r[r[i]]);           
    }
    

    free(p);
    free(r);
}