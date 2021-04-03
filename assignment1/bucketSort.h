#ifndef _MODULE_BUCKET_SORT
#define _MODULE_BUCKET_SORT

#include <algorithm>
#include <vector>

void bucketSort(float arr[], int n)
{

    std::vector<float> b[n];

    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

#endif