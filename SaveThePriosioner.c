//https://www.hackerrank.com/challenges/save-the-prisoner/problem?h_r=next-challenge&h_v=zen
#include<stdio.h>

int main(){
    int t,n,m,s;
    int answer;

    scanf("%d", &t);   
   
    for(int i = 0; i<t; i++){
        scanf("%d%d%d",&n,&m,&s);

        //s is 1-based, (s-1) 0 based
        //must count the last sweet distributed. M-1
        answer = ((s-1) + (m-1)) %n + 1;
        

        printf("%d\n",answer);
    }

}