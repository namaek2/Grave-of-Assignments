#include <iostream>

using namespace std;

void selection(int n, int arr[])
{
   int comp = 0, swap = 0;
   int k, l;

   for (int i = n - 1; i > 0; i--)
   {
      k = 0;

      for (int j = 1; j <= i; j++)
      {
         comp++;
         if (arr[j] > arr[k])
         {
            k = j;
         }
      }

      if (k != i)
      {
         swap++;
         l = arr[k];
         arr[k] = arr[i];
         arr[i] = l;
      }
   }

   cout<<"comp: "<< comp <<", swap: " << swap<<"\n";

   return;
}

void bubble(int n, int arr[])
{
   int comp = 0;
   int swap = 0;
   int l;

   for (int i = n - 1; i >= 0; i--)
   {
      for (int j = 0; j < i; j++)
      {
         comp++;
         if (arr[j] > arr[j + 1])
         {
            swap++;
            l = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = l;
         }
      }
   }
   cout << "comp: " << comp << ", swap: " << swap<<"\n";

   return;
}

void insertion(int n, int arr[])
{
   int l = 0;
   int k = 0;
   int comp = 0;
   int swap = 0;

   for (int i = 1; i < n; i++)
   {
      l = i - 1;
      k = arr[i];

      while (l >= 0)
      {
         comp++;
         if (k < arr[l])
         {
            swap++;
            arr[l+1] = arr[l];
            l = l - 1;
         }

         else
            break;

      }

      swap++;
      arr[l + 1] = k;
   }
   cout << "comp: " << comp << ", swap: " << swap << "\n";
   
   return;
}

int main(void)
{
   int n = 0;
   int a[10000] = { 0, };
   int a1[10000] = { 0, };
   int a2[10000] = { 0, };
   int a3[10000] = { 0, };
   
   cin>>n;

   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
      a1[i] = a[i]; 
      a2[i] = a[i]; 
      a3[i] = a[i];
   }

   selection(n, a1);
   bubble(n, a2);
   insertion(n, a3);
}
