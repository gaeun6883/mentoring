//mentoring 106. 2022.1.31
//bfs알고리즘

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#define MAX 103
using namespace std;

int n, land_cnt = 1;
int map[MAX][MAX] = { 0, }, visited[MAX][MAX] = { 0, };
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void land_bfs(int i, int j);
int bridge_bfs();
int bfs(int i, int j, int t);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;//입력
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++)//섬 라벨 붙이기
		for (int j = 0; j < n; j++)
			if (map[i][j]==1) {
				land_cnt++;
				land_bfs(i, j);
			}

	cout << bridge_bfs();//최소 다리 길이 구하는 함수
	return 0;
}

void land_bfs(int i, int j) {
	queue<pair<int, int>> Q;
	Q.push({ i,j });
	map[i][j] = land_cnt;
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (map[nx][ny] == 1) {
				map[nx][ny] = land_cnt;
				Q.push({ nx, ny });
			}
		}
	}
}

int bridge_bfs() {
	int bridge_cnt = INT_MAX;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (!map[i][j]) {
				int t = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (map[nx][ny] != t && map[nx][ny]) {
						t = map[nx][ny];
						int cnt = bfs(i, j, t);
						bridge_cnt = min(bridge_cnt, cnt);
					}
				}
			}
		}
	return bridge_cnt;
}

int bfs(int i, int j, int t) {
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			visited[x][y] = 0;

	queue<pair<pair<int, int>, int>> Q;//<i,j,cnt>
	Q.push({ { i,j },0 });
	visited[i][j] = 1;

	while (!Q.empty()) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int cnt = Q.front().second;
		Q.pop();

		if (map[x][y] && map[x][y] != t)//반환 조건
			return cnt;

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (map[nx][ny] != t && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				Q.push({ { nx, ny }, ++cnt });
			}
		}
	}
	return -1;//오류
}
