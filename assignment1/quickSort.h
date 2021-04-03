#ifndef _MODULE_QUICK_SORT
#define _MODULE_QUICK_SORT

template <typename T>
void swap(T *a, T *b)
{
    T t = *a;
    *a = *b;
    *b = t;
}

template <typename T>
int partition(T arr[], int low, int high, long long int &count)
{
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
            count++;
        }
        count++;
    }
    swap<T>(&arr[i + 1], &arr[high]);
    count++;
    return (i + 1);
}

template <typename T>
int random_partition(T arr[], int low, int high, long long int &count)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);

    count++;
    swap<T>(&arr[random], &arr[high]);

    return partition(arr, low, high, count);
}

template <typename T>
void quickSort(T arr[], int low, int high, long long int &count, bool randomPivot = false)
{
    count++;
    if (low >= high)
        return;

    int pi;

    if (randomPivot)
        pi = random_partition<T>(arr, low, high, count);
    else
        pi = partition<T>(arr, low, high, count);

    quickSort(arr, low, pi - 1, count, randomPivot);
    quickSort(arr, pi + 1, high, count, randomPivot);
}

#endif