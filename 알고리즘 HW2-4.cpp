#include <iostream>

using namespace std;

void change(int d[], int i, int j)
{
    int l;

    l = d[i];
    d[i] = d[j];
    d[j] = l;
}

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

            change(arr, i, j);
        }
    }

    change(arr, right, i + 1);

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
	int n;

	cin >> n;

    int* day = new int[n];
    int* month = new int[n];
    int* year = new int[n];
    int * fin = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> day[i] >> month[i] >> year[i];
        fin[i] = 0;
    }

    for (int i = 0; i < n; i++)
        fin[i] = day[i] + month[i] * 100 + year[i] * 10000;

    quick_sort(fin, 0, n - 1);
        
    for (int i = 0; i < n; i++)
        cout << (fin[i] - (fin[i] / 10000) * 10000) % 100 << " " << (fin[i] - (fin[i]/10000)*10000)/100 << " " << fin[i] / 10000 << "\n";
}
