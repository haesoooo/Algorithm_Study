#include <iostream>
using namespace std;
#define MAX 101
int N;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y, int depth) {	
    visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;   // range
        if (!visited[nx][ny] && map[nx][ny] > depth) DFS(nx, ny, depth);
	}	
}
int main() {
    cin >> N;
    int hmax = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] > hmax) hmax = map[i][j];
        } 
    }
    int maxregion = 1;
    for (int m = 1; m < hmax; m++) { // 최대 높이까지만 각 높이 별 영역 수 세면 됨
        int ans = 0;
        //memset(visited, 0, sizeof(visited));
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (map[y][x] > m && !visited[y][x]) {
                    ans++;
                    DFS(y, x, m);
                } else visited[y][x] = true;
            }
        } 
        if (maxregion < ans) maxregion = ans;
    }

    cout << maxregion;
}