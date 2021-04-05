#ifndef _MODULE_MOM_
#define _MODULE_MOM_

void insertionSort(short arr[], int initial, int final)
{
    for (int i = initial; i <= final; i++)
    {
        int value = arr[i];
        int pos = i - 1;
        while (pos >= initial && arr[pos] > value)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = value;
    }
}

int findMedian(short arr[], int initial, int final)
{
    insertionSort(arr, initial, final);
    int mid = (initial + final) / 2;
    return arr[mid];
}

int medianOfMedian(short arr[], int size, int divideSize)
{
    if (size < divideSize)
    {
        int median = findMedian(arr, 0, size - 1);
        return median;
    }

    int no_full_group = size / divideSize;
    int elements_in_last = size % divideSize;

    int nextSize;

    if (elements_in_last == 0)
        nextSize = no_full_group;
    else
        nextSize = no_full_group + 1;

    short next[nextSize];

    for (int i = 0; i < nextSize; i++)
    {
        if (i == nextSize - 1)
            next[i] = findMedian(arr, divideSize * i, size - 1);
        else
            next[i] = findMedian(arr, divideSize * i, divideSize * (i + 1) - 1);
    }

    return medianOfMedian(next, nextSize, divideSize);
}

#endif