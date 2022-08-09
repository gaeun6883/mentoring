//mentoring 288. 2022. 8.5
//bfs

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <algorithm>
#define MAX 505
using namespace std;

typedef struct Sejun {
    int x, y, life;
};
int n, m, map[MAX][MAX], visited[MAX][MAX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int bfs();
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
				map[i][j] = 1;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
				visited[i][j] = 1;
	}

	cout<< bfs();
	return 0;
}

int bfs() {
	deque<Sejun> q;
	q.push_back({ 0,0,0 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int life = q.front().life;
		q.pop_front();
		if (x == 500 && y == 500) return life;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nlife = life;
			if (nx < 0 || ny < 0 || nx>500 || ny>500) continue;
			if (!visited[nx][ny]) {
				visited[nx][ny] = 1;
				if (map[nx][ny] == 1) {
					nlife++;
					q.push_back({ nx,ny,nlife });
				}
				else
					q.push_front({ nx,ny,nlife });
			}
		}
	}
	return -1;
}
