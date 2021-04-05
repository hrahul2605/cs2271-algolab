#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mom.h"

const int TOTAL_ITERATION = 10;
const int TOTAL_RUNS = 1000;

int main()
{
    srand(time(0));

    int size = 100000;
    float start, end, time_taken;
    double avg_time;

    FILE *fout = fopen("MoM_obs.csv", "w");
    fprintf(fout, "Divide_Size,Average_Time\n");

    int divide_size;

    short arr[size];

    for (int i = 0; i <= TOTAL_RUNS; i++)
    {
        divide_size = 2 * i + 3;
        avg_time = 0;

        for (int i = 0; i < TOTAL_ITERATION; i++)
        {
            for (int j = 0; j < size; j++)
                arr[j] = rand() % 100;

            start = clock();
            int temp = medianOfMedian(arr, size, divide_size);
            end = clock();

            time_taken = (end - start) * 1000 / CLOCKS_PER_SEC;
            avg_time += time_taken;
        }

        avg_time = avg_time / TOTAL_ITERATION;

        printf("divide_size: %4d avg_time: %3.4f ms\n", divide_size, avg_time);
        fprintf(fout, "%d,%f\n", divide_size, avg_time);
    }

    fclose(fout);
    return 0;
}