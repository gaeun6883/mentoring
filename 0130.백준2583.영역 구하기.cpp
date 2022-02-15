//mentoring 130. 2022.2.12
//bfs

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#define MAX 103
using namespace std;

int m, n, k;
int map[MAX][MAX] = { 0, }, visited[MAX][MAX] = { 0, };
vector<int> answer;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	visited[i][j] = 1;

	int area = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (!map[nx][ny] && !visited[nx][ny]) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
				++area;
			}
		}
	}
	answer.push_back(area);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> k;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}

	for (int i = 0; i < k; i++) {
		int startX, startY, endX, endY;
		cin >> startX >> startY >> endX >> endY;

		for (int y = startY; y < endY; y++)
			for (int x = startX; x < endX; x++)
				map[x][y] = 1;
	}

	int cnt = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if (!visited[i][j] && !map[i][j]) {
				bfs(i, j);
				cnt++;
			}

	cout << cnt<<"\n";
	sort(answer.begin(), answer.end());
	for (int i = 0; i < cnt; i++)
		cout<<answer[i]<<" ";
	return 0;
}
