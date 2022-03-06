//mentoring 164. 2022.3.2
//다이나믹 프로그래밍 + dfs

#include <iostream>
#include <queue>
#include <utility>
#define MAX 503
using namespace std;

int n, m, map[MAX][MAX],dp[MAX][MAX];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int dfs(int x, int y) {
	if (x == m && y == n)
		return 1;
	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx <= 0 || ny <= 0 || nx > m || ny > n) continue;
		if (map[nx][ny] < map[x][y])
			dp[x][y] += dfs(nx, ny);
	}
	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}

	cout << dfs(1, 1);
	return 0;
}
