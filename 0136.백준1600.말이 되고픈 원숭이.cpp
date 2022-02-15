//mentoring 136. 2022.2.15
//bfs

#include <iostream>
#include <queue>
#include <utility>
#define MAX 203
using namespace std;

int k, w, h, map[MAX][MAX], cnt[MAX][MAX][MAX] = { 0, };
int horse_dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int horse_dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int monkey_dx[4] = { 1,0,-1,0 };
int monkey_dy[4] = { 0,1,0,-1 };

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},0 });
	cnt[0][0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int moveN = q.front().second;
		q.pop();
		if (x == h - 1 && y == w - 1)
			return cnt[x][y][moveN];

		if (moveN < k)
			for (int i = 0; i < 8; i++) {
				int nx = x + horse_dx[i];
				int ny = y + horse_dy[i];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (!map[nx][ny] && !cnt[nx][ny][moveN + 1]) {
					cnt[nx][ny][moveN + 1] = cnt[x][y][moveN]+1;
					q.push({ {nx, ny}, moveN + 1 });
				}
			}

		for (int i = 0; i < 4; i++) {
			int nx = x + monkey_dx[i];
			int ny = y + monkey_dy[i];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
			if (!map[nx][ny] && !cnt[nx][ny][moveN]) {
				cnt[nx][ny][moveN] = cnt[x][y][moveN] + 1;
				q.push({ {nx, ny}, moveN });
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> w >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> map[i][j];

	cout << bfs();
	return 0;
}
