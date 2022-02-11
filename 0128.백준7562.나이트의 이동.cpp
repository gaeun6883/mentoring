//mentoring 128. 2022.2.11
//bfs

#include <iostream>
#include <queue>
#include <utility>
#define MAX 303
using namespace std;

int l, visited[MAX][MAX], cnt[MAX][MAX];
int startX, startY, endX, endY;
int dx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ startX, startY });
	visited[startX][startY] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == endX && y == endY) return;
		for (int dir = 0; dir < 8; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
			if (!visited[nx][ny]) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
				cnt[nx][ny] = cnt[x][y] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> l;
		cin >> startX >> startY >> endX >> endY;

		for (int i = 0; i < l; i++)
			for (int j = 0; j < l; j++) {
				visited[i][j] = 0;
				cnt[i][j] = 0;
			}

		bfs();

		cout << cnt[endX][endY]<<"\n";
	}
	return 0;
}
