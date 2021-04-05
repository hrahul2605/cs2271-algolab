#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mom.h"

int main()
{
    srand(time(0));

    int size = 10;

    short arr[size];

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;

    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";

    std::cout << "\n";

    short temp[size];

    for (int i = 0; i < size; i++)
        temp[i] = arr[i];

    printf("Median of Median: %d\n", medianOfMedian(arr, size, 5));
    printf("Normal Method: %d\n", findMedian(temp, 0, size - 1));

    return 0;
}