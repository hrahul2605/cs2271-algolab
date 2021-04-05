#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mom.h"
#include "utils.h"
#include "generateRandomNumbersUD.h"

const int MAX_SIZE = 1e5;
const int DIVIDE_SIZE = 5;
const int TOTAL_ITERATION = 10;

void swap(short *a, short *b)
{
    short c = *a;
    *a = *b;
    *b = c;
}

int partition(short *arr, int initial, int final)
{
    int pivot = arr[initial];

    int left = initial;
    int right = final;

    while (true)
    {
        while (arr[left] < pivot)
            left++;

        while (pivot < arr[right])
            right--;

        if (arr[left] == arr[right])
        {
            if (left == right)
                return left;
            else
                right--;
        }
        else if (left < right)
            swap(&arr[left], &arr[right]);
        else
            return left;
    }
}

int findPartitionSize(short *arr, int size, int divideSize)
{
    int val = medianOfMedian(arr, size, divideSize);

    for (int i = 0; i < size; i++)
        if (arr[i] == val)
        {
            swap(&arr[0], &arr[i]);
            return partition(arr, 0, size - 1);
        }
}

int main()
{
    srand(time(0));

    int partSize;
    float averagePartSize;

    // FILE *fout = fopen("MoM_uniform_obs.csv", "w");
    // fprintf(fout, "size,avg_partition_size\n");

    std::string fileName = "large_data_set.txt";
    generateUDAndWriteToFile(fileName.c_str());

    for (int size = 100; size <= MAX_SIZE; size += 100)
    {
        short arr[size];
        averagePartSize = 0;

        for (int i = 0; i < TOTAL_ITERATION; i++)
        {
            readFromFileToArray(arr, size, fileName.c_str());

            partSize = findPartitionSize(arr, size, DIVIDE_SIZE);

            averagePartSize += partSize;
        }

        averagePartSize = averagePartSize / TOTAL_ITERATION;

        printf("array_size: %d averagePartSize: %f \n", size, averagePartSize);
        // fprintf(fout, "%d,%f\n", size, averagePartSize);
    }

    // fclose(fout);
    return 0;
}