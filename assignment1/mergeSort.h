#ifndef _MODULE_MERGE_SORT
#define _MODULE_MERGE_SORT

#include <iostream>
#include <fstream>

template <typename T>
void merge(T arr[], int l, int m, int r, long long int &count)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    T L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    count += n1 + n2;

    int leftIndex = 0;
    int rightIndex = 0;
    int index = l;

    while (leftIndex < n1 && rightIndex < n2)
    {
        if (L[leftIndex] <= R[rightIndex])
        {
            arr[index] = L[leftIndex];
            leftIndex++;
            count++;
        }
        else
        {
            arr[index] = R[rightIndex];
            rightIndex++;
            count++;
        }
        index++;
        count++;
    }

    while (leftIndex < n1)
    {
        arr[index] = L[leftIndex];
        leftIndex++;
        index++;
        count++;
    }

    while (rightIndex < n2)
    {
        arr[index] = R[rightIndex];
        rightIndex++;
        index++;
        count++;
    }
}

template <typename T>
void mergeSort(T arr[], int l, int r, long long int &count)
{
    if (l >= r)
        return;

    int m = l + (r - l) / 2;
    mergeSort<T>(arr, l, m, count);
    mergeSort<T>(arr, m + 1, r, count);
    merge<T>(arr, l, m, r, count);
    count++;
}
#endif