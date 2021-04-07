#include <iostream>
#include <fstream>
#include <iomanip>
#include "generateRandomNumbersND.h"
#include "generateRandomNumbersUD.h"
#include "utils.h"
#include "mergeSort.h"
#include "quickSort.h"

const int MAX_POW = 18;

using namespace std;

template <typename T>
double runSort(const char *fileName, int size, long long int &count, bool performMerge)
{
    T array[size];
    readFromFileToArray<T>(array, size, fileName);

    clock_t start, end;

    if (performMerge)
    {
        cout << "Starting Merge Sort.\n";
        start = clock();
        mergeSort<T>(array, 0, size - 1, count);
    }
    else
    {
        cout << "Starting Quick Sort\n";
        start = clock();
        quickSort<T>(array, 0, size - 1, count);
    }

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    int check = checkForCorrectness<T>(array, size);

    if (check)
        cout << "Sorted Array is correct.\n";
    else
        cout << "Sorted Array is incorrect.\n";

    string writeFileName = "merge_sorted.txt";

    if (check)
        writeFromArrayToFile<T>(array, size, writeFileName.c_str());

    cout << "\n";
    return time_taken;
}

int main()
{
    string writeFile = "large_data_set.txt";
    ofstream FILE;
    FILE.open("Result3_UD.csv");

    cout << "Generating Random Numbers from Uniform Distribution.\n";
    generateUDAndWriteToFile(writeFile.c_str());

    long long int index = 2;

    FILE << "Using Merge Sort,,\n";
    FILE << "Number of elements,Time Taken, Operations\n";
    for (int i = 1; i < MAX_POW; i++)
    {
        int size = pow(2, i);
        long long int count = 0;
        double totalTimeTaken = 0.0;
        totalTimeTaken = runSort<int>(writeFile.c_str(), size, count, true);
        // FILE << "Time Taken for sorting UD Data set using Merge Sort, ";
        FILE << size;
        FILE << ",";
        // FILE << " elements ";
        FILE << totalTimeTaken * 1e4;
        FILE << ",";
        // FILE << " seconds ";
        // FILE << "No. of operations: ";
        FILE << count;
        FILE << "\n";
    }

    FILE << "Using Quick Sort,,\n";
    FILE << "Number of elements,Time Taken, Operations\n";

    index = 2;

    for (int i = 1; i < MAX_POW; i++)
    {
        int size = pow(2, i);
        long long int count = 0;
        double totalTimeTaken = 0.0;
        totalTimeTaken = runSort<int>(writeFile.c_str(), size, count, false);
        // FILE << "Time Taken for sorting UD Data set using Quick Sort, ";
        FILE << size;
        FILE << ",";
        // FILE << " elements ";
        FILE << totalTimeTaken * 1e4;
        FILE << ",";
        // FILE << " seconds ";
        // FILE << "No. of operations: ";
        FILE << count;
        FILE << "\n";
    }

    cout << "Generating Random Numbers from Normal Distribution.\n";
    generateNDAndWriteToFile(writeFile.c_str());
    FILE.close();
    FILE.open("Result3_ND.csv");

    FILE << "Using Merge Sort,,\n";
    FILE << "Number of elements,Time Taken, Operations\n";
    index = 2;

    for (int i = 1; i < MAX_POW; i++)
    {
        int size = pow(2, i);
        long long int count = 0;
        double totalTimeTaken = 0.0;
        totalTimeTaken = runSort<float>(writeFile.c_str(), size, count, true);
        // FILE << "Time Taken for sorting ND Data set using Merge Sort, ";
        FILE << size;
        FILE << ",";
        // FILE << " elements ";
        FILE << totalTimeTaken * 1e4;
        FILE << ",";
        // FILE << " seconds ";
        // FILE << "No. of operations: ";
        FILE << count;
        FILE << "\n";
    }

    index = 2;

    FILE << "Using Quick Sort,,\n";
    FILE << "Number of elements,Time Taken, Operations\n";
    for (int i = 1; i < MAX_POW; i++)
    {
        int size = pow(2, i);
        long long int count = 0;
        double totalTimeTaken = 0.0;
        totalTimeTaken = runSort<float>(writeFile.c_str(), size, count, false);
        // FILE << "Time Taken for sorting UD Data set using Merge Sort, ";
        FILE << size;
        FILE << ",";
        // FILE << " elements ";
        FILE << totalTimeTaken * 1e4;
        FILE << ",";
        // FILE << " seconds ";
        // FILE << "No. of operations: ";
        FILE << count;
        FILE << "\n";
    }
    return 0;
}