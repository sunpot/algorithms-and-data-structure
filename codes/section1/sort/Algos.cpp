//
// Created by Takahashi, Wataru on 2019-05-31.
//

#include "Algos.h"

void Algos::CombSort(int n, int *data){
    int i, temp, flag, gap;
    gap = n;
    do{
        gap = (gap * 10) / 13;
        if(gap == 0){
            gap = 1;
        }

        flag = 1;

        for(i = 0;i < n - gap;i++){
            if (data[i] > data[i+gap]){
                flag = 0;
                temp = data[i];
                data[i] = data[i + gap];
                data[i + gap] = temp;
            }
        }
    } while ((gap> 1) || flag != 1);
}

void Algos::MergeSort(int n, int x[]){
    int i, j, k, m;
    int buffer[n];

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

void Algos::QuickSort(int bottom, int top, int *data){
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

void Algos::BubbleSort(int n, int *data){
    int i, j, flag, k;

    k = 0;
    do{
        flag = 0;
        for(i = 0; i < n-1-k; i++){
            if(data[i] > data[i+1]){
                flag = 1;
                j = data[i];
                data[i] = data[i+1];
                data[i+1] = j;
            }
        }
        k++;
    } while (flag == 1);
}