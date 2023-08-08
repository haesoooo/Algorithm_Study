// #include <iostream>
// using namespace std;

// int N, M;
// char Map[101][101]; // 맵
// int Visit[101][101]; // 방문 표시

// int dx[4] = { 1, 0, -1, 0 };
// int dy[4] = { 0, 1, 0, -1 };
// int Min = 10001;

// void DFS(int x, int y, int depth)
// {
	
// 	if (x < 0 || y < 0 || x >= N || y >= M) return;   // range
// 	if (x == N - 1 && y == M - 1) { // 도착할 때
// 		if (depth < Min) Min = depth;
// 		return;
// 	}

// 	for (int i = 0; i < 4; i++) {
// 		int nx = x + dx[i];
// 		int ny = y + dy[i];
// 		if (Visit[nx][ny] == 0 && Map[nx][ny] == '1') {
// 			Visit[nx][ny] = 1;
// 			DFS(nx, ny, depth + 1);
// 			Visit[nx][ny] = 0;
// 		}
// 	}
	
// }

// int main() {
// 	cin >> N >> M;
// 	for (int i = 0; i < N; i++)	cin >> Map[i];
// 	DFS(0, 0, 1);
// 	cout << Min;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std;

//int x, y;
int M, N, K;
int cnt = 0;
int map[201][201] = { 0, };
int IsCheck[201][201] = { 0, };
int dist[201][201] = { 0, };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	IsCheck[x][y] = 1;
	dist[x][y] = 1;

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			if (map[nx][ny] == 0)
				continue;

			if (map[nx][ny] == 1 && IsCheck[nx][ny] == 0)
			{
				dist[nx][ny] = dist[a][b] + 1;
				q.push(make_pair(nx, ny));
				IsCheck[nx][ny] = 1;
			}
		}
	}

	return dist[N - 1][M - 1];
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}

	cout << bfs(0, 0);

	return 0;
}