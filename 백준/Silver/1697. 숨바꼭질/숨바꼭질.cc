#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int n, int m)
{
	queue<pair<int, int> > q;
	pair<int, int> pos;
	int *visited = new int[500000];

	q.push(make_pair(n, 0));
	for (int i = 0; i < m * 2; i++)
		visited[i] = 0;
	while (!q.empty())
	{
		pos = q.front();
		q.pop();
		if (pos.first == m)
		{
			free(visited);
			return (pos.second);
		}
		visited[pos.first] = 1;
		if (pos.first + 1 <= m && !visited[pos.first + 1])
			q.push(make_pair(pos.first + 1, pos.second + 1));
		if (pos.first - 1 >= 0 && !visited[pos.first - 1])
			q.push(make_pair(pos.first - 1, pos.second + 1));
		if (pos.first < m && !visited[pos.first * 2])
			q.push(make_pair(pos.first * 2, pos.second + 1));
	}
	return (-1);
}

int main(void)
{
	int n;
	int m;

	cin >> n >> m;
	cout << bfs(n, m) << endl;
}
