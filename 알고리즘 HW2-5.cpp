#include <iostream>

using namespace std;

long long inv=0;

void merge(int arr[], int left, int middle, int right)
{
    int i = left;
    int j = middle + 1;
    int t = 0;

    int* temp = new int[right - left + 1];

    while ((i <= middle) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[t++] = arr[i++];
        }


        else
        {
            inv+=(middle-i+1);
            temp[t++] = arr[j++];
        }

    }

    while (i <= middle)
    {
        temp[t++] = arr[i++];
    }

    while (j <= right)
    {
        temp[t++] = arr[j++];
    }

    i = left;
    t = 0;

    while (i <= right)
    {
        arr[i++] = temp[t++];
    }

    delete[] temp;
}

void merge_sort(int arr[], int left, int right)
{
    int middle = 0;

    if (left < right)
    {
        middle = (left + right) / 2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }

    return;
}


int main(void)
{
    int n;

    cin >> n;

    int* a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    merge_sort(a, 0, n - 1);
    cout << inv;
}
