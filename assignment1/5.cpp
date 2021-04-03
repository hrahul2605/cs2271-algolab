#include <iostream>
#include <time.h>
#include "generateRandomNumbersUD.h"
#include "bucketSort.h"
#include "utils.h"

using namespace std;

const int TOTAL_RUNS = 10;

int main()
{

    string fileName = "data_set_between_0_1.txt";
    string resultFileName = "result_5.txt";
    clock_t start, end;
    ofstream FILE;
    FILE.open(resultFileName);
    double total_time_taken = 0.0;
    for (int i = 0; i < TOTAL_RUNS; i++)
    {
        cout << "Generating Random Data set between 0 and 1.\n";
        int size = 1e5;
        generateUDBetweenZeroAndOne(fileName.c_str(), MINIMUM_UD_RANGE, MAXIMUM_UD_RANGE, size);
        float array[size];

        readFromFileToArray<float>(array, size, fileName.c_str());
        cout << "Starting Bucket sort.\n";
        start = clock();
        bucketSort(array, size);
        end = clock();

        total_time_taken += double(end - start) / double(CLOCKS_PER_SEC);

        cout << "Starting to check for Correctness\n";
        int correct = checkForCorrectness<float>(array, size);

        if (correct)
            cout << "Correct.\n";
    }

    FILE << "Avg. Time Taken for sorting UD Data set using Merge Sort, ";
    FILE << TOTAL_RUNS;
    FILE << " runs ";
    FILE << total_time_taken / TOTAL_RUNS;
    FILE << " seconds ";
    FILE << "\n";

    FILE.close();

    return 0;
}