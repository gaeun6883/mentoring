//mentoring 134. 2022.2.14
//bfs

#include <iostream>
#include <queue>
#include <utility>
#define MAX 1003
using namespace std;

int n, m, map[MAX][MAX], cnt[MAX][MAX][2];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs() {
	queue<pair<pair<int, int>, int>> q;//<x,y,can_break_block_cnt>
	q.push({ {0,0},1 });
	cnt[0][0][1] = 1;

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
				q.push({ {nx, ny},0 });
				cnt[nx][ny][0] = cnt[x][y][1] + 1;
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

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
			cnt[i][j][0]=cnt[i][j][1] = 0;
		}
	}

	int result=bfs();

	cout << result;
	return 0;
}

//초기 bfs코드: 논리오류
/*void bfs() {
	queue<pair<pair<int, int>, int>> q;//<x,y,can_break_block_cnt>
	q.push({ {0,0},1 });
	visited[0][0] = 1;
	cnt[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int breakN = q.front().second;
		q.pop();
		if (x == n - 1 && y == m - 1)
			return;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] || (!breakN && map[nx][ny] == 1)) continue;
			if (breakN && map[nx][ny] == 1)
				q.push({ {nx, ny}, 0 });
			else q.push({ { nx, ny }, breakN });
			cnt[nx][ny] = cnt[x][y] + 1;
			visited[nx][ny] = 1;
		}
	}
	state = false;
}*/
