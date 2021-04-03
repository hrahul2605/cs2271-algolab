#include <iostream>
#include "generateRandomNumbersND.h"
#include "mergeSort.h"
#include "utils.h"

int main()
{

    std::string file = "nd_data_set.txt";
    generateNDAndWriteToFile(file.c_str());

    float array[TOTAL_ND];

    readFromFileToArray<float>(array, TOTAL_ND, file.c_str());
    long long int count = 0;
    mergeSort<float>(array, 0, TOTAL_ND - 1, count);
    writeFromArrayToFile<float>(array, TOTAL_ND, file.c_str());
    return 0;
}