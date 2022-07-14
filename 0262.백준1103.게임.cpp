//mentoring 262. 2022.7.9
//dfs & dp

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 55
using namespace std;
int n,m, map[MAX][MAX], dp[MAX][MAX], result=0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int a, int b, int cnt) {
	result = max(result, cnt);
	if (a < 0 || a >= n || b < 0 || b >= m) return;
	if (result > n * m || map[a][b] == -1 || cnt <= dp[a][b]) return;

	dp[a][b] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = a + dx[i] * map[a][b];
		int ny = b + dy[i] * map[a][b];
		dfs(nx, ny, cnt + 1);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			if (s[j] == 'H') map[i][j] = -1;
			else map[i][j] = s[j] - '0';
	}
	memset(dp, -1, sizeof(dp));

	dfs(0, 0, 0);
	if (result > n * m) result = -1;
	cout << result;
	return 0;
}
