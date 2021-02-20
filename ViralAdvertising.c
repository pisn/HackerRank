//https://www.hackerrank.com/challenges/strange-advertising/problem
#include<stdio.h>
#include<math.h>

int main(){
    int day, dayLikes, totalLikes;
    int i;

    scanf("%d", &day);

    dayLikes = 2; // floor(5/2)
    totalLikes = 2;

    for(i=1;i<day;i++){
        dayLikes = (dayLikes * 3)/2;        
        totalLikes += dayLikes;
    }    

    printf("%d\n",totalLikes);
}