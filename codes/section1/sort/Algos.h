//
// Created by Takahashi, Wataru on 2019-05-31.
//

#ifndef SORT_ALGOS_H
#define SORT_ALGOS_H


class Algos {
public:
    void BinaryInsertSort(int n, int data[]);
    void InsertSort(int n, int data[]);
    void CombSort(int n, int data[]);
    void MergeSort(int n, int data[]);
    void QuickSort(int bottom, int top, int *data);
    void BubbleSort(int n, int data[]);
};


#endif //SORT_ALGOS_H
