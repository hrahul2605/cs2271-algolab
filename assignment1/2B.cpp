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
double runSort(const char *fileName, int size)
{
    T array[size];
    readFromFileToArray<T>(array, size, fileName);

    clock_t start, end;
    cout << "Starting Quick Sort.\n";
    start = clock();
    long long int count = 0;
    quickSort<T>(array, 0, size - 1, count);

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    int check = checkForCorrectness<T>(array, size);

    if (check)
        cout << "Sorted Array is correct.\n";
    else
        cout << "Sorted Array is incorrect.\n";

    string writeFileName = "quick_sorted.txt";

    if (check)
        writeFromArrayToFile<T>(array, size, writeFileName.c_str());

    cout << "\n";
    return time_taken;
}

double run(bool fromUD)
{
    string writeFile = "large_data_set.txt";

    if (fromUD)
    {
        cout << "Generating Random Numbers from Uniform Distribution.\n";
        generateUDAndWriteToFile(writeFile.c_str());

        return runSort<int>(writeFile.c_str(), TOTAL_UD);
    }
    else
    {
        cout << "Generating Random Numbers from Normal Distribution.\n";
        generateNDAndWriteToFile(writeFile.c_str());

        return runSort<float>(writeFile.c_str(), TOTAL_ND);
    }
}

int main()
{
    ofstream FILE;
    FILE.open("result_2B.txt");
    double totalTimeTaken = 0.0;

    for (int i = 0; i < TOTAL_RUNS; i++)
        totalTimeTaken += run(true);

    FILE << "Average Time Taken for sorting UD Data set using Quick Sort, ";
    FILE << TOTAL_RUNS;
    FILE << " runs ";
    FILE << totalTimeTaken / TOTAL_RUNS;
    FILE << " seconds.\n";

    for (int i = 0; i < TOTAL_RUNS; i++)
        totalTimeTaken += run(false);

    FILE << "Average Time Taken for sorting ND Data set using Quick Sort, ";
    FILE << TOTAL_RUNS;
    FILE << " runs ";
    FILE << totalTimeTaken / TOTAL_RUNS;
    FILE << " seconds.\n";

    return 0;
}