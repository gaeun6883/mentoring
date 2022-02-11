//mentoring 126. 2022.2.10
//bfs

#include <iostream>
#include <queue>
#include <utility>
#define MAX 103
using namespace std;

int n, map[MAX][MAX], visited[MAX][MAX];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	visited[i][j] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (!visited[nx][ny] && map[nx][ny] == map[x][y]) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = 0;
	int cnt_1 = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if (!visited[i][j]) {
				bfs(i, j);
				cnt_1++;
			}

	int cnt_2 = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
			if (map[i][j] == 'G')
				map[i][j] = 'R';
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j]) {
				bfs(i, j);
				cnt_2++;
			}

	cout << cnt_1 << " " << cnt_2;
	return 0;
}
