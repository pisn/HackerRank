#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int sumGeoProg(int n, int q,int a1){
    return a1*(pow(q,n)-1)/(q-1);
}

int utopianTree(int n) {
    // Complete this function
    //Formula can be analysed with two distinct parts
    //One is a simple power component, which starts at 2^0, and go all way through ceil(n/2). Executed at each odd step
    //The other is a Geometric progression. This is a little harder to get, but starting at step two, every odd step
    //adds another 1 in the summation, and multiply the rest for two. Creating a G.P starting at 1 with step 2. 


    return (pow(2,ceil((float)n/2.0f)) + sumGeoProg(floor((float)n/2.0f),2,1)*((n%2)+ 1));
}

int main() {
    int t; 
    scanf("%i", &t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%i", &n);
        int result = utopianTree(n);
        printf("%d\n", result);
    }
    return 0;
}
