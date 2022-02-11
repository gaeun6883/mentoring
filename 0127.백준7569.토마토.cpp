//mentoring 127. 2022.2.10
//bfs

#include <iostream>
#include <queue>
#include <utility>
#define MAX 103
using namespace std;

int m, n, h;
int map[MAX][MAX][MAX], visited[MAX][MAX][MAX] = { 0, }, day[MAX][MAX][MAX] = { 0, };
queue<pair<pair<int, int>, int>> q;
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nz = z + dz[dir];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
			if (!map[nx][ny][nz]&&!visited[nx][ny][nz]&&!day[nx][ny][nz]) {
				q.push({ {nx, ny}, nz });
				map[nx][ny][nz] = 1;
				visited[nx][ny][nz] = 1;
				day[nx][ny][nz] = day[x][y][z] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;
	bool state = true;
	for (int k = 0; k < h; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 0) state = false;
				if (map[i][j][k] == 1) {
					visited[i][j][k] = 1;
					q.push({ { i,j },k });
				}
			}
	if (state) {
		cout << 0;
		return 0;
	}

	bfs();

	int result = 0;
	for (int k = 0; k < h; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (map[i][j][k] == 0) {
					cout << "-1";
					return 0;
				}
				result = max(result, day[i][j][k]);
			}
	cout << result;
	return 0;
}
