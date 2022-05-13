//mentoring 229. 2022.5.11
//bfs 응용 & 구현

#include <iostream>
#include <vector>
#include <queue>
#define MAX 55
using namespace std;

int r, c, t, map[MAX][MAX], result = 0;
int dx[4]= { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

vector<pair<int, int>> v;
vector<pair<pair<int, int>,int>> dust;

void clean();
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> t;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1)
				v.push_back({ i,j });
		}

	while (t--) {
		dust.clear();
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (map[i][j] > 0) {
					dust.push_back({ {i,j}, map[i][j] });
					map[i][j] = 0;
				}

		for (int i = 0; i < dust.size(); i++) {//spread
			int x = dust[i].first.first;
			int y = dust[i].first.second;
			int d = dust[i].second/5;
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
				if (map[nx][ny] != -1) {
					cnt++;
					map[nx][ny] += d;
				}
			}
			dust[i].second -= (cnt * d);
			map[x][y] += dust[i].second;
		}

		clean();
	}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (map[i][j]>0)
				result += map[i][j];

	cout << result;
	return 0;
}

void clean() {
	int a = v[0].first;
	int b = v[1].first;

	for (int i = a - 1; i > 0; i--)
		map[i][0] = map[i - 1][0];

	for (int j = 0; j < c - 1; j++)
		map[0][j] = map[0][j + 1];

	for (int i = 0; i < a; i++)
		map[i][c - 1] = map[i + 1][c - 1];

	for (int j = c - 1; j > 0; j--) {
		map[a][j] = map[a][j - 1];
		if (map[a][j] == -1) map[a][j] = 0;
	}

	for (int i = b+ 1; i < r - 1; i++)
		map[i][0] = map[i + 1][0];

	for (int j = 0; j < c - 1; j++)
		map[r - 1][j] = map[r - 1][j + 1];

	for (int i = r - 1; i >  b; i--)
		map[i][c - 1] = map[i - 1][c - 1];

	for (int j = c - 1; j > 0; j--) {
		map[b][j] = map[b][j - 1];
		if (map[b][j] == -1) map[b][j] = 0;
	}
}
