//mentoring 139. 2022.2.16
//bfs

#include <iostream>
#include <queue>
#include <utility>
#define MAX 1003
using namespace std;

int n, m,k, map[MAX][MAX], cnt[MAX][MAX][12];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs() {
	queue<pair<pair<int, int>, int>> q;//<x,y,can_break_block_cnt>
	q.push({ {0,0},k });
	cnt[0][0][k] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int breakN = q.front().second;
		q.pop();
		if (x == n - 1 && y == m - 1)
			return cnt[x][y][breakN];
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (breakN && map[nx][ny]) {
				q.push({ {nx, ny}, breakN-1 });
				cnt[nx][ny][breakN-1] = cnt[x][y][breakN] + 1;
			}
			else if (!map[nx][ny] && !cnt[nx][ny][breakN]) {
				q.push({ {nx, ny}, breakN });
				cnt[nx][ny][breakN] = cnt[x][y][breakN] + 1;
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
			for (int t = 0; t < 12; t++) {
				cnt[i][j][t] = 0;
			}
		}
	}

	cout<< bfs();
	return 0;
}
