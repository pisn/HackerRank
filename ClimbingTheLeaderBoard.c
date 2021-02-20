//https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
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
 * Complete the climbingLeaderboard function below.
 */

/*
 * Please store the size of the integer array to be returned in result_count pointer. For example,
 * int a[3] = {1, 2, 3};
 *
 * *result_count = 3;
 *
 * return a;
 *
 */
int* climbingLeaderboard(int scores_count, int* scores, int alice_count, int* alice, int* result_count) {
    /*
     * Write your code here.
     */
    int i,j,prevScore=0,adjScoreCount=0;
    *result_count = alice_count;
    int *result = (int*) malloc(alice_count*sizeof(int));
    
    /*for(i=0;i<scores_count;i++){
        if(prevScore==scores[i])
            continue;
        
        prevScore = scores[i];
        adjusted_score[adjScoreCount] = scores[i];
        adjScoreCount++;
    }*/
    j=0;
    for(i=alice_count-1;i>=0;i--){
        //adjScoreCount = 0;
        //prevScore = 0;
        for(j;j<scores_count;j++){              
            if(prevScore!=scores[j]){
                prevScore = scores[j];               
                adjScoreCount++;
            }
            
            if (alice[i]>=scores[j]){                    
                break; 
            }            
        }        
        if(j==scores_count){
            result[i] = adjScoreCount+1;
        }
        else{
            result[i] = adjScoreCount;     
        }        
        
    }                
    

    return result;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* scores_count_endptr;
    char* scores_count_str = readline();
    int scores_count = strtol(scores_count_str, &scores_count_endptr, 10);

    if (scores_count_endptr == scores_count_str || *scores_count_endptr != '\0') { exit(EXIT_FAILURE); }

    char** scores_temp = split_string(readline());

    int scores[scores_count];

    for (int scores_itr = 0; scores_itr < scores_count; scores_itr++) {
        char* scores_item_endptr;
        char* scores_item_str = scores_temp[scores_itr];
        int scores_item = strtol(scores_item_str, &scores_item_endptr, 10);

        if (scores_item_endptr == scores_item_str || *scores_item_endptr != '\0') { exit(EXIT_FAILURE); }

        scores[scores_itr] = scores_item;
    }

    char* alice_count_endptr;
    char* alice_count_str = readline();
    int alice_count = strtol(alice_count_str, &alice_count_endptr, 10);

    if (alice_count_endptr == alice_count_str || *alice_count_endptr != '\0') { exit(EXIT_FAILURE); }

    char** alice_temp = split_string(readline());

    int alice[alice_count];

    for (int alice_itr = 0; alice_itr < alice_count; alice_itr++) {
        char* alice_item_endptr;
        char* alice_item_str = alice_temp[alice_itr];
        int alice_item = strtol(alice_item_str, &alice_item_endptr, 10);

        if (alice_item_endptr == alice_item_str || *alice_item_endptr != '\0') { exit(EXIT_FAILURE); }

        alice[alice_itr] = alice_item;
    }

    int result_count;
    int* result = climbingLeaderboard(scores_count, scores, alice_count, alice, &result_count);

    for (int result_itr = 0; result_itr < result_count; result_itr++) {
        fprintf(fptr, "%d", result[result_itr]);

        if (result_itr != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

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
