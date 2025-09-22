/*
3 sorting
1. Selection
2. Insertion
3. Bubble

Time Complexity - O(n^2)
*/

#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int s, int e)
{
    int i, j;
    int pivot = arr[e];
    i = s - 1;
    for (j = 0; j < e; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[e]);
    return i + 1;
}

void quickSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int pivot = partition(arr, s, e);
        quickSort(arr, s, pivot - 1);
        quickSort(arr, pivot + 1, e);
    }
}

// Display function
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    display(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    display(arr, size);

    return 0;
}

//
// selection sort function
/*void selectSort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
*/

/*// merge function
void merge(int arr[], int s, int e, int mid)
{
    int i, j;
    int n1 = mid - s + 1;
    int n2 = e - mid;

    int Larr[n1], Rarr[n2];

    for (i = 0; i < n1; i++)
        Larr[i] = arr[s + i];
    for (j = 0; j < n2; j++)
        Rarr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    int k = s;

    while (i < n1 && j < n2)
    {
        if (Larr[i] < Rarr[j])
            arr[k++] = Larr[i++];
        else
            arr[k++] = Rarr[j++];
    }

    while (i < n1)
        arr[k++] = Larr[i++];
    while (j < n2)
        arr[k++] = Rarr[j++];
}

// merge sort function
void mergeSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int mid = s + (e - s) / 2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);
        merge(arr, s, e, mid);
    }
}*/