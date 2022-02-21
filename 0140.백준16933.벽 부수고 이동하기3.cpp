//mentoring 140. 2022.2.17
//bfs

#include <iostream>
#include <queue>
#include <tuple>
#define MAX 1003
using namespace std;

int n, m, k, map[MAX][MAX], cnt[MAX][MAX][12][2];//0: day, 1:night
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs() {
	queue < tuple<int, int, int, int>> q;//<x,y,can_break_block_cnt, day/night>
	q.push({0,0,k,0});
	cnt[0][0][k][0] = 1;

	while (!q.empty()) {
		int x, y, breakN, state;
		tie(x, y, breakN, state) = q.front();
		q.pop();
		if (x == n - 1 && y == m - 1)
			return cnt[x][y][breakN][state];
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (!map[nx][ny] && !cnt[nx][ny][breakN][1 - state]) {
				cnt[nx][ny][breakN][1 - state] = cnt[x][y][breakN][state] + 1;
				q.push({nx, ny, breakN, 1 - state});
			}
			if (!state && breakN && map[nx][ny] && !cnt[nx][ny][breakN - 1][1 - state]) {
				cnt[nx][ny][breakN - 1][1 - state] = cnt[x][y][breakN][state] + 1;
				q.push({nx, ny, breakN - 1, 1 - state});
			}
		}
		if (!cnt[x][y][breakN][1 - state]) {
			cnt[x][y][breakN][1 - state] = cnt[x][y][breakN][state] + 1;
			q.push({ x, y, breakN, 1 - state });
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
				cnt[i][j][t][0]=cnt[i][j][t][1] = 0;
			}
		}
	}

	cout << bfs();
	return 0;
}
