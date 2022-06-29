#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector <int>vrr[500002];

void topo(int arr[], int num)
{
   queue<int>q;

   for (int i = 1; i <= num; i++)
   {
      if (arr[i] == 0)
         q.push(i);
   }

   for (int i = 1; i <= num; i++)
   {
      if (q.empty())
      {
         cout << "Yes";
         return;
      }

      int k = q.front();
      q.pop();

      for (int i = 0; i < vrr[k].size(); i++)
      {
         int t = vrr[k][i];

         if (--arr[t] == 0)
         {
            q.push(t);
         }
      }
   }

   cout << "No";
}

int main(void)
{
   int un, vn;
   cin >> un >> vn;

   int* arr = new int[un+1];

   for (int i = 1; i <= vn; i++)
   {
      int a, b;
      cin >> a >> b;
      vrr[a].push_back(b);
      arr[b]++;
   }
   
   topo(arr, un);
}
