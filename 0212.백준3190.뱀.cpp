//mentoring 212. 2022.4.7
//bfs

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAX 103
using namespace std;

int n, k, l, map[MAX][MAX], result = 0;
vector<pair<int, char>> v;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int turnD(char c, int d);
void bfs(int startX, int startY) {
	deque<pair<int, int>> Q;
	Q.push_back({ startX, startY });
	map[startX][startY] = 2;

	int x = startX, y = startY, d = 0, idx = 0;
	while (!Q.empty()) {
		result++;
		int nx = x + dx[d];
		int ny = y + dy[d];
		if ((nx < 0 || ny < 0 || nx >= n || ny >= n) || map[nx][ny] == 2) break;
		if (!map[nx][ny]) {
			map[nx][ny] = 2;
			map[Q.back().first][Q.back().second] = 0;
			Q.pop_back();
			Q.push_front({ nx, ny });
		}
		else if (map[nx][ny] == 1) {
			map[nx][ny] = 2;
			Q.push_front({ nx, ny });
		}
		if (idx < v.size())
			if (result == v[idx].first) {
				if (v[idx].second == 'L') d = turnD('L', d);
				else if (v[idx].second == 'D') d = turnD('D', d);
				idx++;
			}
		x = nx;
		y = ny;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int a;
		char b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	bfs(0, 0);
	cout << result;
	return 0;
}

int turnD(char c, int d) {
	if (c == 'L') {
		if (d == 0) return 3;
		if (d == 1) return 2;
		if (d == 2) return 0;
		if (d == 3) return 1;
	}
	if (c == 'D') {
		if (d == 0) return 2;
		if (d == 1) return 3;
		if (d == 2) return 1;
		if (d == 3) return 0;
	}
}
