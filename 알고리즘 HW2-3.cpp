#include <iostream>

using namespace std;

int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;
    int l;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            i = i + 1;

            l = arr[i];
            arr[i] = arr[j];
            arr[j] = l;
        }
    }

    l = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = l;

    return i + 1;
}

void quick_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int p = partition(arr, left, right);

        quick_sort(arr, left, p - 1);
        quick_sort(arr, p + 1, right);
    }
}



int main(void)
{
   int n, m;
   int count = 0;

   cin >> n >> m;

   int* a = new int[n];

   for (int i = 0; i < n; i++)
      cin >> a[i];

   quick_sort(a, 0, n-1);

    int l = 0, r = n - 1;

    while (1)
    {
        if (l >= r)
        {
            break;
        }

        if (m - a[l] == a[r])
        {
            l++;
            r--;
            count++;
        }

        else if (m - a[l] < a[r])
            r--;
        else
            l++;
    }

    cout << count;
}
