#include <bits/stdc++.h>
using namespace std;

void quicksort(int a[], int low, int high);
void printarray(int a[], int size);
int partition(int a[], int low, int high);

int main()
{
    int a[] = {5, 3, 2, 1, 4, 6, 8, 7};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "\n before unsorted array : " << "\n";
    printarray(a, n);

    quicksort(a, 0, n - 1);

    cout << " after sorted array : " << "\n";
    printarray(a, n);

    return 0;
}

void printarray(int a[], int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << "\n\n";
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int left = low;
    int right = high;

    while (left < right)
    {
        while (a[left] <= pivot)
        {
            left++;
        }
        while (a[right] > pivot)
        {
            right--;
        }

        if (left < right)
        {
            swap(a[left], a[right]);
        }
    }

    swap(a[low], a[right]);
    return right;
}

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int pvt_idx = partition(a, low, high);

        quicksort(a, low, pvt_idx - 1);
        quicksort(a, pvt_idx + 1, high);
    }
}