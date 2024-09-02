#include <stdio.h>

int arr[10];
int size = 0;

void insert(int arr[], int d);
void printArray(int arr[], int n);
void heapify(int arr[], int size, int i);

int main()
{
    insert(arr, 0);
    insert(arr, 3);
    insert(arr, 1);
    insert(arr, 6);
    insert(arr, 5);

    printf("Before sorting, the array elements are:\n");
    printArray(arr, size);
    printf("\n");

    
    int i;

 
    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }


    for (i = size - 1; i >= 0; i--)
    {
        
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

       
        heapify(arr, i, 0);
    }

    printf("After sorting, the array elements are:\n");
    printArray(arr, size);
    printf("\n");

    return 0;
}


void insert(int arr[], int d)
{
    int i;
    if (size >= 10)
    {
        printf("Array is full, cannot insert more elements.\n");
        return;
    }

    arr[size] = d;
    size++;

   
    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
}


void heapify(int arr[], int size, int i)
{
    int m = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[m])
    {
        m = left;
    }

    if (right < size && arr[right] > arr[m])
    {
        m = right;
    }

    if (m != i)
    {
        int temp = arr[i];
        arr[i] = arr[m];
        arr[m] = temp;

        heapify(arr, size, m);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
}