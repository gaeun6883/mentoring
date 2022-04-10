//mentoring 215. 2022.4.10
//dfs,bfs

#include <iostream>
#include <queue>
#include <utility>
#define MAX 10
using namespace std;

int n, m, map[MAX][MAX], result = 0;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void check();
void dfs(int cnt) {
	if (cnt == 3) {
		check();
		return;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!map[i][j]) {
				map[i][j] = 1;
				dfs(cnt + 1);
				map[i][j] = 0;
			}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if (!map[i][j]) {
				map[i][j] = 1;
				dfs(1);
				map[i][j] = 0;
			}

	cout << result;
	return 0;
}

void check() {
	int board[MAX][MAX];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			board[i][j] = map[i][j];

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] == 2)
				q.push({ i,j });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (!board[nx][ny]) {
				board[nx][ny] = 2;
				q.push({ nx,ny });
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!board[i][j])
				cnt++;
	result = max(result, cnt);
}
