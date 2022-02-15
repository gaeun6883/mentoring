//mentoring 133. 2022.2.13
//bfs

#include <iostream>
#include <queue>
#include <utility>
#define MAX 33
using namespace std;

int l, r, c, visited[MAX][MAX][MAX], cnt[MAX][MAX][MAX];
char map[MAX][MAX][MAX];
int startX, startY, startZ, result;
bool state;
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

void reset();
void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { startX, startY }, startZ });
	visited[startX][startY][startZ] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();
		if (map[x][y][z] == 'E') {
			result = cnt[x][y][z];
			return;
		}
		for (int dir = 0; dir < 6; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nz = z + dz[dir];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= r || ny >= c || nz >= l) continue;
			if (!visited[nx][ny][nz] && map[nx][ny][nz] != '#') {
				visited[nx][ny][nz] = 1;
				q.push({ {nx, ny }, nz});
				cnt[nx][ny][nz] = cnt[x][y][z] + 1;
			}
		}
	}
	state = false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;
		for(int k=0; k<l; k++)
			for(int i=0; i<r; i++)
				for (int j = 0; j < c; j++) {
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S') {
						startX = i;
						startY = j;
						startZ = k;
					}
				}

		reset();
		bfs();

		if (!state)
			cout << "Trapped!\n";
		else cout << "Escaped in " << result << " minute(s).\n";
	}
	return 0;
}

void reset() {
	state = true;
	for (int k = 0; k < l; k++)
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				visited[i][j][k] = 0;
				cnt[i][j][k] = 0;
			}
}
