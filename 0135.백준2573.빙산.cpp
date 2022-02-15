//mentoring 135. 2022.1.14
//bfs

#include <iostream>
#include <queue>
#include <utility>
#define MAX 1003
using namespace std;

int n, m, map[MAX][MAX], visited[MAX][MAX], later_map[MAX][MAX], land_cnt;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void reset();
void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	visited[i][j] = 1;

	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 && ny < 0 && nx >= n && ny >= m) continue;
			if (!visited[nx][ny] && later_map[nx][ny]) {
				visited[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}
int melt(int i, int j) {
	int cnt = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = i + dx[dir];
		int ny = j + dy[dir];
		if (!map[nx][ny])
			cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	int year = 1;
	while (true) {
		for (int i = 0; i < n; i++)//1년 후 빙산 지도
			for (int j = 0; j < m; j++)
				if (map[i][j]) {
					later_map[i][j] = map[i][j] - melt(i, j);
					if (later_map[i][j] < 0)
						later_map[i][j] = 0;
				}

		reset();
		for (int i = 0; i < n; i++)//빙산 개수 bfs
			for (int j = 0; j < m; j++)
				if (later_map[i][j] && !visited[i][j]) {
					bfs(i, j);
					land_cnt++;
				}
		if (land_cnt != 1) break;

		for (int i = 0; i < n; i++)//1년 후(later map)->현재(map)
			for (int j = 0; j < m; j++)
				map[i][j] = later_map[i][j];
		++year;
	}

	if (land_cnt == 0) cout << 0;
	else cout << year;
	return 0;
}

void reset() {
	land_cnt = 0;
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = 0;
}
