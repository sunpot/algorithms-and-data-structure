#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>

#define N 1000000
int sort[N];// = {9,7,6,2,8,1,4,3,5,10};
int buffer[N];

void MergeSort(int n, int x[]){
    int i, j, k, m;

    if(n <= 1){
        return;
    }
    m = n/2;

    MergeSort(m, x);
    MergeSort(n-m, x+m);

    for(i = 0;i < m; i++){
        buffer[i] = x[i];
    }
    j = m;
    i = k = 0;

    while(i < m && j < n){
        x[k++] = buffer[i] < x[j] ? buffer[i++] : x[j++];
    }
    while(i < m){
        x[k++] = buffer[i++];
    }
}

void BubbleSort(){
    int i, j, flag, k;

    k = 0;
    do{
        flag = 0;
        for(i = 0; i < N-1-k; i++){
            if(sort[i] > sort[i+1]){
                flag = 1;
                j = sort[i];
                sort[i] = sort[i+1];
                sort[i+1] = j;
            }
        }
        k++;
    } while (flag == 1);
}

void QuickSort(int bottom, int top, int *data){
    int lower, upper, div, temp;
    if(bottom >= top) return;

    div = data[bottom];
    for(lower = bottom, upper = top; lower < upper;){
        while(lower <= upper && data[lower] <= div){
            lower++;
        }
        while(lower <= upper && data[upper] > div){
            upper--;
        }
        if(lower < upper){
            temp = data[lower];
            data[lower] = data[upper];
            data[upper] = temp;
        }
    }

    temp = data[bottom];
    data[bottom] = data[upper];
    data[upper] = temp;

    QuickSort(bottom, upper-1, data);
    QuickSort(upper+1, top, data);
}

void print(){
    for(int i = 0; i < N; i++){
        printf("%d ", sort[i]);
    }
}

int main() {
    int i;
    srand((unsigned int)time(NULL));

    printf("Prepare for sort: \n");
    for(i = 0; i < N; i++){
        sort[i] = rand();
    }

    printf("\nStart sorting. \n");
    std::chrono::system_clock::time_point  start, end; // 型は auto で可
    start = std::chrono::system_clock::now(); // 計測開始時間
    //BubbleSort();
    //QuickSort(0, N-1, sort);
    MergeSort(N, sort);
    end = std::chrono::system_clock::now();  // 計測終了時間
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    //print();
    printf("\nFinish sorting. Elapsed: %f [ms]\n", elapsed);
    return (int)EXIT_SUCCESS;
}