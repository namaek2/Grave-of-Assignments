#include <iostream>

using namespace std;

int comp = 0, swap1 = 0;

void merge(int arr[], int left, int middle, int right)
{
   int i = left;
   int j = middle + 1;
   int t = 0;

   int* temp = new int[right - left + 1];

   while ((i <= middle) && (j <= right))
   {
      comp++;
      if (arr[i] <= arr[j])
      {
         temp[t++] = arr[i++];
         swap1++;
      }
         
      
      else
      {
         swap1++;
         temp[t++] = arr[j++];
      }
         
   }

   while (i <= middle)
   {
      temp[t++] = arr[i++];
      swap1++;
   }
   
   while (j <= right)
   {
      temp[t++] = arr[j++];
      swap1++;
   }

   i = left;
   t = 0;

   while (i <= right)
   {
      arr[i++] = temp[t++];
      swap1++;
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

int partition(int arr[], int left, int right)
{
   int pivot = arr[right];
   int i = left - 1;
   int l;

   for (int j = left; j < right; j++)
   {
      comp++;
      if (arr[j] <= pivot)
      {
         i = i + 1;

         swap1++;
         l = arr[i];
         arr[i] = arr[j];
         arr[j] = l;
      }
   }
      
   swap1++;
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

void down_heap(int arr[], int i, int n)
{
   int left = 2 * i;
   int right = 2 * i + 1;
   int largest = i;

   if (left <= n)
   {
      comp++;
      if (arr[left] > arr[largest])
      {
         largest = left;
      }
         
   }

   if (right <= n)
   {
      comp++;
      if (arr[right] > arr[largest])
      {
         largest = right;
      }
         
   }
   
   if (largest != i)
   {
      swap1++;

      int l = arr[i];
      arr[i] = arr[largest];
      arr[largest] = l;

      down_heap(arr, largest, n);
   }
}

void heap_sort(int arr[], int n)
{
   int l;

   for (int i = (n/2); i >= 1; i--)
      down_heap(arr, i, n);

   for (int i = n; i >= 2; i--)
   {
      swap1++;

      l = arr[i];
      arr[i] = arr[1];
      arr[1] = l;

      down_heap(arr, 1, i-1);
   }
}



int main(void)
{
   int n = 0;

   cin >> n;

   int* a = new int[n];
   int* a1 = new int[n];
   int* a2 = new int[n+1];
   
   

   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
      a1[i] = a[i]; 
      a2[i+1] = a[i]; 
   }

   merge_sort(a, 0, n-1);
   cout << "comp: " << comp << ", swap: " << swap1 << "\n";
   comp = 0;
   swap1 = 0;

   quick_sort(a1, 0, n-1);
   cout << "comp: " << comp << ", swap: " << swap1 << "\n";
   comp = 0;
   swap1 = 0;

   heap_sort(a2, n);
   cout << "comp: " << comp << ", swap: " << swap1 << "\n";
   


   delete[] a;
   delete[] a1;
   delete[] a2;

   return 0;
}
