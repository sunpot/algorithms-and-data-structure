#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include "Algos.h"


void print(int n, int *data){
    for(int i = 0; i < n; i++){
        printf("%d ", data[i]);
    }
}

int main() {
    int i, n = 10000;
    int sort[n];// = {9,7,6,2,8,1,4,3,5,10};
    std::chrono::system_clock::time_point  start, end; // 型は auto で可
    auto algos = new Algos();
    srand((unsigned int)time(NULL));

    printf("Prepare for sort: \n");
    for(i = 0; i < n; i++){
        sort[i] = rand();
    }

    printf("\nStart sorting. \n");
    start = std::chrono::system_clock::now(); // 計測開始時間

    algos->BubbleSort(n, sort);
//    algos->QuickSort(0, n-1, sort);
//    algos->MergeSort(n, sort);
//    algos->CombSort(n, sort);

    end = std::chrono::system_clock::now();  // 計測終了時間
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

    //print(n, sort);
    printf("\nFinish sorting. Elapsed: %f [ms]\n", elapsed);
    return (int)EXIT_SUCCESS;
}