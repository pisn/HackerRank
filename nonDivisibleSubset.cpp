#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,k,i,r;    
    int restos[101];
    int combinacoesPossiveis = 0;
    int maxSize = 0, numMaxSize=0;

    scanf("%d%d",&n,&k);

    int* s = new int[n];    
    memset(s,0,sizeof(s));
    memset(restos,0,sizeof(restos));

    for(i=0; i<n; i++){
        scanf("%d", &s[i]);
        r = s[i] % k;
        restos[r] = restos[r] + 1;
    }

    //For any k, numbers with s[i] % k == a and s[j] % k == b, where (a+b) == k cannot be together. Any
    //other combination is acceptable, but groups of numbers with remaining sum is k is prohibted. Lets 
    //use a gummy algorithm to select always the largest groups for every a and b possible


    for(i=0; i<= k/2; i++){
        if(i == 0 || (k %2 == 0 && i == k/ 2)){
            if(restos[i] > 0){
                numMaxSize++; //When remaining is 0 (evenly divides k) or is exactly k/2, only one number of these groups are allowed. Summing two numbers with s%k==0 or s%k == k/2 creates a multiple.
            }
        }        
        else { //for remainings a and b where a + b == k, choose largest group selected.
            maxSize = restos[i];
            
            if(restos[k-i] > maxSize){
                maxSize = restos[k-i];
            }

            numMaxSize += maxSize;
        }

    }

    printf("%d", numMaxSize);

    free(s);
    
}