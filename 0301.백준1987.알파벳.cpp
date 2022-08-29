//mentoring 301. 2022.8.18
//dfs

#include <iostream>
#define MAX 26
using namespace std;

int r, c, map[MAX][MAX], visited[MAX], result = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int a, int b, int cnt) {
	result = max(result, cnt);

	for (int i = 0; i < 4; i++) {
		int nx = a + dx[i];
		int ny = b + dy[i];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if (!visited[map[nx][ny]]) {
			visited[map[nx][ny]] = 1;
			dfs(nx, ny, cnt + 1);
			visited[map[nx][ny]] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			char c;
			cin >> c;
			map[i][j] = c - 'A';
		}

	visited[map[0][0]] = 1;
	dfs(0, 0, 1);

	cout << result;
	return 0;
}
