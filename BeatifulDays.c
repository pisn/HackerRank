//https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem
#include<stdio.h>
#include<math.h>

int main(){
    int i,j,k;
    int revert;
    int r,potencia, day, magnitude;
    int finalCount = 0;

    scanf("%d", &i);
    scanf("%d", &j);
    scanf("%d", &k);

    for(;i<=j;i++){
        day = i;
        revert = 0;        
        magnitude = log10(day) ;
        potencia = pow(10, magnitude);

        while(day>0){
            r = day % 10;
            
            revert  = revert + potencia*r;
            potencia = potencia/10;            

            day = day/10;
        }

        revert = i - revert;

        if(revert < 0)
            revert= -revert;

        if(revert % k == 0){
            finalCount++;
        }
    }

    printf("%d\n",finalCount);

}
