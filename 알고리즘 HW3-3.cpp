#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

vector<pair<int, int>> vrr[500001];

void dijk(int s, long long arr[])
{
   arr[s] = 0;

   priority_queue<pair<long long, int>> q;

   q.push({ 0, s });

   while (!q.empty())
   {
      long long dis = -q.top().first;

      long long a = q.top().second;

      q.pop();


      if (arr[a] < dis)
         continue;


      for (int i = 0; i < vrr[a].size(); i++)
      {
         long long cost = vrr[a][i].first;

         long long nd = vrr[a][i].second;
            
         if (cost + dis< arr[nd])
         {
            arr[nd] = dis + cost;
            q.push({ -arr[nd], nd});
         }
      }
   }
}

int main(void)
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int n, m;
   int s;

   cin >> n >> m;
   cin >> s;
   

   long long* arr = new long long[n+1];

   for (int i = 1; i <= m; i++)
   {

      int w, u, v;
      cin >> u >> v >> w;

      vrr[u].push_back({ w, v });
      vrr[v].push_back({ w, u });
      arr[u] = INF; arr[v] = INF;

   }
   dijk(s, arr);

   for (int i = 1; i <= n; i++)
   {
      if (arr[i] == INF)
         printf("INF\n");
      else
         cout << arr[i] << "\n";
   }

   return 0;
}
