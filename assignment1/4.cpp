#include <iostream>
#include <fstream>
#include <iomanip>
#include "generateRandomNumbersND.h"
#include "generateRandomNumbersUD.h"
#include "utils.h"
#include "quickSort.h"

const int TOTAL_RUNS = 5;

using namespace std;

template <typename T>
double runSort(const char *fileName, long long int &count)
{
    T array[TOTAL_ND];
    readFromFileToArray<T>(array, TOTAL_ND, fileName);

    clock_t start, end;
    cout << "Starting Quick Sort\n";
    start = clock();
    quickSort<T>(array, 0, TOTAL_ND - 1, count, true);

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    int check = checkForCorrectness<T>(array, TOTAL_ND);

    if (check)
        cout << "Sorted Array is correct.\n";
    else
        cout << "Sorted Array is incorrect.\n";

    string writeFileName = "quick_sorted.txt";

    if (check)
        writeFromArrayToFile<T>(array, TOTAL_ND, writeFileName.c_str());

    cout << "\n";
    return time_taken;
}

int main()
{
    string writeFile = "large_data_set.txt";
    ofstream FILE;
    FILE.open("Result4_UD.csv");

    FILE << "Total Run, Time Taken, No. of operations, Average Time Taken, Average No Operations\n";

    long long int index = 2;

    long long int totalCount = 0;
    double totalTimeTaken = 0.0;

    for (int i = 0; i < TOTAL_RUNS; i++)
    {
        cout << "Generating Random Numbers from Uniform Distribution.\n";
        generateUDAndWriteToFile(writeFile.c_str());

        long long int count = 0;
        double timeTaken = 0.0;
        timeTaken = runSort<int>(writeFile.c_str(), count);

        // FILE << "Time Taken for sorting UD Data set using Randomized Quick Sort, ";
        // FILE << " 1 run ";
        FILE << "1,";
        FILE << timeTaken;
        FILE << ",";
        // FILE << " seconds ";
        // FILE << "No. of operations: ";
        FILE << count;
        FILE << ",,";
        FILE << "\n";

        totalCount += count;
        totalTimeTaken += timeTaken;
    }

    // FILE << "\n\nTime Taken for sorting UD Data set using Randomized Quick Sort, ";
    FILE << TOTAL_RUNS;
    FILE << ",";
    // FILE << " runs ";
    FILE << ",,";
    FILE << totalTimeTaken / TOTAL_RUNS;
    // FILE << " seconds ";
    // FILE << "Avg. No. of operations: ";
    FILE << ",";
    FILE << totalCount / TOTAL_RUNS;
    // FILE << "\n\n";
    FILE << "\n";

    FILE.close();
    FILE.open("Result4_ND.csv");
    FILE << "Total Run, Time Taken, No. of operations, Average Time Taken, Average No Operations\n";

    totalCount = 0;
    totalTimeTaken = 0.0;

    for (int i = 0; i < TOTAL_RUNS; i++)
    {
        cout << "Generating Random Numbers from Normal Distribution.\n";
        generateNDAndWriteToFile(writeFile.c_str());

        long long int count = 0;
        double timeTaken = 0.0;
        timeTaken = runSort<float>(writeFile.c_str(), count);

        // FILE << "Time Taken for sorting ND Data set using Randomized Quick Sort, ";
        // FILE << " 1 run ";
        // FILE << timeTaken;
        // FILE << " seconds ";
        // FILE << "No. of operations: ";
        // FILE << count;
        // FILE << "\n";

        // FILE << "Time Taken for sorting UD Data set using Randomized Quick Sort, ";
        // FILE << " 1 run ";
        FILE << "1,";
        FILE << timeTaken;
        FILE << ",";
        // FILE << " seconds ";
        // FILE << "No. of operations: ";
        FILE << count;
        FILE << ",,";
        FILE << "\n";

        totalCount += count;
        totalTimeTaken += timeTaken;
    }

    // FILE << "\n\nTime Taken for sorting ND Data set using Randomized Quick Sort, ";
    // FILE << TOTAL_RUNS;
    // FILE << " runs ";
    // FILE << totalTimeTaken / TOTAL_RUNS;
    // FILE << " seconds ";
    // FILE << "Avg. No. of operations: ";
    // FILE << totalCount / TOTAL_RUNS;
    // FILE << "\n\n";

    // FILE << "\n\nTime Taken for sorting UD Data set using Randomized Quick Sort, ";
    FILE << TOTAL_RUNS;
    FILE << ",";
    // FILE << " runs ";
    FILE << ",,";
    FILE << totalTimeTaken / TOTAL_RUNS;
    // FILE << " seconds ";
    // FILE << "Avg. No. of operations: ";
    FILE << ",";
    FILE << totalCount / TOTAL_RUNS;
    // FILE << "\n\n";
    FILE << "\n";

    FILE.close();

    return 0;
}