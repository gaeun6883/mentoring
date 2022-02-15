//mentoring 132. 2022.2.13
//bfs

#include <iostream>
#include <queue>
#include <utility>
#define MAX 103
using namespace std;

int n, map[MAX][MAX], visited[MAX][MAX];
int cnt = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void reset();
void bfs(int i, int j, int height) {
	queue < pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] >= height && !visited[nx][ny]) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int maxH=0, minH=MAX;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int h;
			cin >> h;
			map[i][j] = h;
			maxH = max(maxH, h);
			minH = min(minH, h);
		}

	int maxCnt = 0;
	for (int h = minH; h <= maxH; h++) {
		reset();
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if (map[i][j] >= h && !visited[i][j]) {
					bfs(i, j, h);
					cnt++;
				}
		maxCnt = max(maxCnt, cnt);
	}

	cout << maxCnt;
	return 0;
}

void reset() {
	cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = 0;
}
