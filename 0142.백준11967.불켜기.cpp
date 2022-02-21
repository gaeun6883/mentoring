//mentoring 142. 2022.2.18
//bfs

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define MAX 103
using namespace std;

int n, m, x, y, a, b, result = 1;
int map[MAX][MAX], visited[MAX][MAX];
vector <pair<int, int>> v[MAX][MAX];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs() {
	queue <pair<int, int>> q;
	q.push({ 1,1 });
	visited[1][1] = 1;
	map[1][1] = 1;

	for (auto room : v[1][1]) {//[1][1]방의 모든 불 켜기
		if (!map[room.first][room.second]) {
			map[room.first][room.second] = 1;
			result++;
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (auto& room : v[x][y]) {
			int roomX = room.first;
			int roomY = room.second;
			if (!map[roomX][roomY]) { 
				map[roomX][roomY] = 1;
				result++;
				for (int dir = 0; dir < 4; dir++) {
					int nx = roomX + dx[dir];
					int ny = roomY + dy[dir];
					if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
					if (visited[nx][ny]) {
						q.push({ roomX,roomY });
						visited[roomX][roomY] = 1;
						break;
					}
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
			if (!visited[nx][ny] && map[nx][ny]) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> a >> b;
		v[x][y].push_back({ a,b });
	}

	bfs();
	cout << result;
}
