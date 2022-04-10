//mentoirng 211. 2022.4.6
//bfs, 방향 전환 

#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
#define MAX 55
using namespace std;

int n, m, r, c, d, map[MAX][MAX], visited[MAX][MAX], result=1;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


int turnD(int d);
void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { r, c }, d });
	visited[r][c] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();
		bool state = false;
		int ndir = dir;
		for (int i = 0; i < 4; i++) {//2a
			ndir = turnD(ndir);
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (!map[nx][ny] && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				state = true;
				q.push({ {nx, ny}, ndir });
				result++;
				break;
			}
		}

		if (!state) {//2b
			int nx = x - dx[dir];
			int ny = y - dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (!map[nx][ny])
				q.push({ {nx, ny}, dir });
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	memset(visited, 0, sizeof(visited));

	bfs();
	cout << result;
	return 0;
}

int turnD(int d) {
	if (d == 0) return 3;
	if (d == 1) return 0;
	if (d == 2) return 1;
	if (d == 3) return 2;
	return -1;
}
