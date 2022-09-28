#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int s1, s2;
int t1, t2;
char arr[51][51];
int vis[51][51];

void BFS(int a, int b)
{
	queue<pair<int, int>> q;
	q.push({ a, b });
	vis[a][b] = 1;

	int da[4] = { 1, 0, -1, 0 };
	int db[4] = { 0, 1, 0, -1 };

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = cur.first + da[i];
			int y = cur.second + db[i];

			if (x < 0 || y < 0)
				continue;
			else if (x >= n || y >= m)
				continue;

			if (arr[x][y] != '1' && vis[x][y] == 0)
			{
				vis[x][y] = vis[cur.first][cur.second] + 1;
				q.push({ x, y });
			}
		}
	}
}


int main(void)
{

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];

			vis[i][j] = 0;

			if (arr[i][j] == 'T')
			{
				t1 = i;
				t2 = j;
			}

			else if (arr[i][j] == 'S')
			{
				s1 = i;
				s2 = j;
			}
		}
	}

	BFS(s1, s2);

	if (vis[t1][t2] == 0)
		cout << "0";

	else
		cout << vis[t1][t2];
	

	return 0;
}
