#include <bits/stdc++.h>
using namespace std;

void quicksort(int a[], int l, int h);
void printarray(int a[], int size);

int main()
{
    int a[] = {10, 7, 9, 8, 3, 2, 15, 1};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "before sorting" << "\n";
    printarray(a, n);

    quicksort(a, 0, n - 1);

    cout << "after sorting" << "\n";
    printarray(a, n);

    return 0;
}

void printarray(int a[], int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l;
    int j = h;

    while (i < j)
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }

    swap(a[l], a[j]);
    return j;
}

void quicksort(int a[], int l, int h)
{
    if (l < h)
    {
        int pvt_idx = partition(a, l, h);

        quicksort(a, l, pvt_idx - 1);
        quicksort(a, pvt_idx + 1, h);
    }
}