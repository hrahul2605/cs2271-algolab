#ifndef _MODULE_BUCKET_SORT
#define _MODULE_BUCKET_SORT

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

typedef struct LL
{
    float data;
    struct LL *next;
} node;

node *LLInsertSorted(node *list, float d, int *count)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = d;

    if (list == NULL)
    {
        list = newNode;
        (*count)++;
    }
    else if (newNode->data < list->data)
    {
        newNode->next = list;
        list = newNode;
        (*count)++;
    }
    else
    {
        node *temp = list;

        while ((temp->next != NULL) && (!((temp->data <= newNode->data) && ((temp->next)->data >= newNode->data))))
        {
            temp = temp->next;
            (*count) += 2;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    return list;
}

node *deleteStart(node *list, float *d)
{
    node *temp = list;
    list = list->next;

    *d = temp->data;
    free(temp);

    return list;
}

void bucketSort(float *arr, int n, int *count)
{
    node *bins[n];

    for (int i = 0; i < n; i++)
        bins[i] = NULL;

    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        pos = n * arr[i];

        bins[pos] = LLInsertSorted(bins[pos], arr[i], count);
        (*count)++;
    }

    pos = 0;
    float temp;

    for (int i = 0; i < n; i++)
    {
        while (bins[i] != NULL)
        {
            bins[i] = deleteStart(bins[i], &temp);
            arr[pos] = temp;
            pos++;
        }
    }
}

#endif