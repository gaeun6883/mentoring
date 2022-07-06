//mentoring 252. 2022.6.26
//priority_queue & bfs

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 22
using namespace std;

int n, map[MAX][MAX], visited[MAX][MAX];
int baby = 2, eat_cnt = 0, result = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,-0,1 };
struct shark{
	int d, x, y;
	bool operator < (const shark &a) const {
		if (d == a.d)
			if (x == a.x)
				return y > a.y;
			else return x > a.x;
		else return d > a.d;
	}
};
priority_queue<shark> q;

void bfs() {
	while (!q.empty()) {
		int dist = q.top().d;
		int x = q.top().x;
		int y = q.top().y;
		q.pop();

		if (map[x][y] > 0 && map[x][y] < baby) {
			eat_cnt++;
			map[x][y] = 0;
			if (baby == eat_cnt) {
				baby++;
				eat_cnt = 0;
			}
			result += dist;

			dist = 0;
			memset(visited, 0, sizeof(visited));
			while (!q.empty())
				q.pop();
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (!visited[nx][ny] && map[nx][ny] <= baby) {
				q.push({ dist + 1,nx,ny });
				visited[nx][ny] = 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0;
				q.push({ 0,i,j });
			}
		}

	bfs();
	cout << result;
	return 0;
}
