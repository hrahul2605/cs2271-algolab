#include <iostream>
#include <time.h>
#include "generateRandomNumbersUD.h"
#include "generateRandomNumbersND.h"
#include "bucketSort.h"
#include "utils.h"

using namespace std;

const int TOTAL_RUNS = 5;

double run(bool fromUD)
{
    string fileName = "data_set_between_0_1.txt";
    clock_t start, end;

    int size = 1e5;
    if (fromUD)
    {
        cout << "Generating Random UD Data set between 0 and 1.\n";
        generateUDBetweenZeroAndOne(fileName.c_str(), MINIMUM_UD_RANGE, MAXIMUM_UD_RANGE, size);
    }
    else
    {
        cout << "Generating Random ND Data set between 0 and 1.\n";
        generateNDBetweenZeroAndOne(fileName.c_str(), MEAN, STANDARD_DEVIATION, size);
    }
    float array[size];

    readFromFileToArray<float>(array, size, fileName.c_str());
    cout << "Starting Bucket sort.\n";
    start = clock();
    bucketSort(array, size);
    end = clock();

    cout << "Starting to check for Correctness\n";
    int correct = checkForCorrectness<float>(array, size);

    if (correct)
        cout << "Correct.\n";

    return double(end - start) / double(CLOCKS_PER_SEC);
}

int main()
{

    string resultFileName = "result_5.txt";
    ofstream FILE;
    FILE.open(resultFileName);
    double total_time_taken = 0.0;
    for (int i = 0; i < TOTAL_RUNS; i++)
        total_time_taken += run(true);

    FILE << "Avg. Time Taken for sorting UD Data set using Merge Sort, ";
    FILE << TOTAL_RUNS;
    FILE << " runs ";
    FILE << total_time_taken / TOTAL_RUNS;
    FILE << " seconds ";
    FILE << "\n";

    total_time_taken = 0.0;
    for (int i = 0; i < TOTAL_RUNS; i++)
        total_time_taken += run(false);

    FILE << "Avg. Time Taken for sorting ND Data set using Merge Sort, ";
    FILE << TOTAL_RUNS;
    FILE << " runs ";
    FILE << total_time_taken / TOTAL_RUNS;
    FILE << " seconds ";
    FILE << "\n";

    FILE.close();

    return 0;
}