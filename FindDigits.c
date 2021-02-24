#include<stdio.h>

int main(){
    int t,n,nt,d, count;

    scanf("%d", &t);

    for(int i =0; i< t; i++){
        scanf("%d",&n);

        nt = n;
        count = 0;

        while(nt > 0){
            d = nt%10;
            nt = nt/10;

            if(d != 0 && n % d == 0){
                count++;
            }
        }
        printf("%d\n", count);
    }
}