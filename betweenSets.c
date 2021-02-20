#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

/*
 * Complete the getTotalX function below.
 */
int getMdc(int a, int b){
    //Euclidean algorithm 

    while(a!= 0 && b!=0){
        if(a > b){
            a -= b;
        }
        else {
            b -= a;
        }
    }

    if(a>b) return a;
    return b;
}

 int getMmc(int a, int b){
    return (a*b)/getMdc(a,b);
 }

int getTotalX(int a_count, int* a, int b_count, int* b) {
    /*
     * Write your code here.
     */
     //First find maximum common divisor of second arrays
     int i,mdc=b[0],mmc =1,finalCount=1;
     for(i=0;i<b_count;i++){
        mdc = getMdc(mdc,b[i]);
        printf("mdc:%d \n",mdc);
     }

     //Then, find the minimum common multple of first arrays
     for(i=0;i<a_count;i++){
        mmc = getMmc(mmc,a[i]);
        printf("mmc:%d \n",mmc);
    }

     //Number between the two arrays must be factors of the common divisor, and multiples of common multiple

     for(i=mmc;i<=mdc; i+=mmc){
        if (mdc%i == 0)
            finalCount++;
     }
     return finalCount;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nm = split_string(readline());

    char* n_endptr;
    char* n_str = nm[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* m_endptr;
    char* m_str = nm[1];
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    char** a_temp = split_string(readline());

    int a[n];

    for (int a_itr = 0; a_itr < n; a_itr++) {
        char* a_item_endptr;
        char* a_item_str = a_temp[a_itr];
        int a_item = strtol(a_item_str, &a_item_endptr, 10);

        if (a_item_endptr == a_item_str || *a_item_endptr != '\0') { exit(EXIT_FAILURE); }

        a[a_itr] = a_item;
    }

    char** b_temp = split_string(readline());

    int b[m];

    for (int b_itr = 0; b_itr < m; b_itr++) {
        char* b_item_endptr;
        char* b_item_str = b_temp[b_itr];
        int b_item = strtol(b_item_str, &b_item_endptr, 10);

        if (b_item_endptr == b_item_str || *b_item_endptr != '\0') { exit(EXIT_FAILURE); }

        b[b_itr] = b_item;
    }

    int total = getTotalX(n, a, m, b);

    fprintf(fptr, "%d\n", total);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
