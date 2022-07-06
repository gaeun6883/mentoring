//mentoring 255. 2022.6.29
//bfs

#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#define MAX 22
using namespace std;

int n, m, k, map[MAX][MAX], visited[MAX][MAX], result = 0;
int dice[7] = { 0,1,2,3,4,5,6 };
int dx[4] = { 0,1,0,-1 };//��������
int dy[4] = { 1,0,-1,0 };
int x=1, y=1, d=0;

void rotate(int d);
int bfs(int a, int b, int t);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];

	while (k--) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 1 || ny < 1 || nx > n || ny > m) {
			d = (d + 2) % 4;
			nx = x + dx[d];
			ny = y + dy[d];
		}
		rotate(d);

		result += bfs(nx, ny, map[nx][ny]);

		int a = map[nx][ny], b = dice[6];
		if (a < b) d = (d + 1) % 4;
		else if (a > b) d = (d + 3) % 4;

		x = nx;
		y = ny;
	}
	cout << result;
	return 0;
}

void rotate(int d) {
	int d1 = dice[1], d2 = dice[2], d3 = dice[3], d4 = dice[4], d5 = dice[5], d6 = dice[6];

	if (d == 0) {
		dice[1] = d4;
		dice[3] = d1;
		dice[4] = d6;
		dice[6] = d3;
	}

	else if (d == 1) {
		dice[1] = d2;
		dice[2] = d6;
		dice[5] = d1;
		dice[6] = d5;
	}

	else if (d == 2) {
		dice[1] = d3;
		dice[3] = d6;
		dice[4] = d1;
		dice[6] = d4;
	}

	else if (d == 3) {
		dice[1] = d5;
		dice[2] = d1;
		dice[5] = d6;
		dice[6] = d2;
	}
}
int bfs(int a, int b, int t) {
	memset(visited, 0, sizeof(visited));

	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 1;

	int cnt = 0;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 1 || ny < 1 || nx > n || ny > m ) continue;
			if (!visited[nx][ny] && map[nx][ny] == t) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
	return cnt*t;
}
