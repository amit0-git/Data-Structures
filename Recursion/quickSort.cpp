#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
    // take first elem as pivot

    int pivot = arr[s];

    // count elem less thn pivot
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // place pivot in right pos
    int pivotIndex = cnt + s;
    swap(arr[pivotIndex], arr[s]);

    // arrange elements on left and right of the pivot
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        // if the element on the left of the pivot is already small
        while (arr[i] < pivot)
        {
            i++;
        }
        // if the element on the right of the element is already bigger
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);

    // sort left part

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}
int main()
{

    int arr[8] = {9, 80, 7, 6, 5, 67, 45, 0};
    quickSort(arr, 0, 7);

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
}