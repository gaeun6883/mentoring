//mentoring 141. 2022.2.17
//bfs

#include <iostream>
#include <queue>
#include <utility>
#include <string>
#define MAX 1003
using namespace std;

int n, m, p, player[12] = { 0, }, area[12] = { 0, };
char map[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> q[12];

void bfs() {
	while (true) {
		for (int t = 1; t <= p; t++) {
			int dist = player[t];
			while (!q[t].empty() && dist--) {
				int s = q[t].size();
				for (int i = 0; i < s; i++) {
					int x = q[t].front().first;
					int y = q[t].front().second;
					q[t].pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = x + dx[dir];
						int ny = y + dy[dir];
						if (nx < 0 && ny < 0 && nx >= n && ny >= m) continue;
						if(map[nx][ny] == '.') {
							map[nx][ny] = t + '0';
							q[t].push({ nx,ny });
							area[t]++;
						}
					}
				}
			}
		}
		bool state= true;
		for (int i = 1; i <= p; i++) {
			if (!q[i].empty()) {
				state = false;
				break;
			}
		}
		if (state) break;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++) {
		cin >> player[i];
		area[i] = 0;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if ('1' <= map[i][j] && map[i][j] <= '9') {
				q[map[i][j] - '0'].push({ i, j });
				area[map[i][j] - '0']++;
			}
		}

	bfs();

	for (int i = 1; i <= p; i++)
		cout << area[i] << " ";
	return 0;
}
