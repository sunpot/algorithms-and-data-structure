#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
short sort[N];

void BubbleSort(void){
    short i, j, flag;

    do{
        flag = 0;
        for(i = 0; i < N - 1; i++){
            if(sort[i] > sort[i+1]){
                flag = 1;
                j = sort[i];
                sort[i] = sort[i+1];
                sort[i+1] = j;
            }
        }
    } while (flag == 1);
}

int main() {
    short i;
    srand((unsigned short)time(NULL));

    printf("Prepare for sort: \n");
    for(i = 0; i < N; i++){
        sort[i] = rand();
        printf("%d ", sort[i]);
    }
    printf("\nStart sorting. \n");
    BubbleSort();

    printf("Finish sorting.\n");
    for(i = 0; i < N; i++){
        printf("%d ", sort[i]);
    }

    return (int)EXIT_SUCCESS;
}