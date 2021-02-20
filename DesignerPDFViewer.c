//https://www.hackerrank.com/challenges/designer-pdf-viewer/problem
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int designerPdfViewer(int* h, char* word) {
    // Complete this function
    int i,maxHeight =0;
    
    for(i =0;i<strlen(word);i++){
        if(h[word[i]-'a']>maxHeight)
            maxHeight = h[word[i]-'a'];
    }
    
    return strlen(word)*maxHeight;
    
}

int main() {
    int *h = malloc(sizeof(int) * 26);
    for (int h_i = 0; h_i < 26; h_i++) {
       scanf("%i",&h[h_i]);
    }
    char* word = (char *)malloc(512000 * sizeof(char));
    scanf("%s", word);
    int result = designerPdfViewer(h, word);
    printf("%d\n", result);
    return 0;
}
