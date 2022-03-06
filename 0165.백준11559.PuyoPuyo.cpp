//mentoring 165. 2022.3.2
//bfs

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char map[12][6];
int visited[12][6];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int bfs(int i, int j, char color) {
	int num = 1;
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
			if (!visited[nx][ny] && map[nx][ny] == color) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
				num++;
			}
		}
	}
	return num;
}
void remove() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			if (visited[i][j])
				map[i][j] = '.';
}
void next_setting() {
	for (int j = 0; j < 6; j++)
		while (true) {
			bool state = false;
			for (int i = 11; i > 0; i--)
				if (map[i][j] == '.' && map[i - 1][j] != '.') {
					map[i][j] = map[i - 1][j];
					map[i - 1][j] = '.';
					state = true;
				}
			if (!state)
				break;
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> map[i][j];

	int combo = 0;
	while (true) {
		bool state = false;
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				for (int i = 0; i < 12; i++)
					for (int j = 0; j < 6; j++)
						visited[i][j] = 0;
				if (map[i][j] != '.') {
					int set=bfs(i, j, map[i][j]);
					if (set >= 4) {
						state = true;
						remove();
					}
				}
			}
		}
		if (!state) break;
		next_setting();
		combo++;
	}

	cout << combo;
	return 0;
}
