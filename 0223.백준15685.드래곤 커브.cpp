//memtoring 223. 2022.5.5
//bfs & 구현

#include <iostream>
#include <vector>
using namespace std;

int n, map[102][102], result = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void sol(int a, int b, int d, int g) {
	vector<int> dir;
	dir.push_back(d);
	int x = a + dx[d];
	int y = b + dy[d];
	map[a][b] = map[x][y] = 1;
	for (int i = 0; i < g; i++) {
		int s = dir.size();
		for (int j = s - 1; j >= 0; j--) {
			int nd = (dir[j] + 1) % 4;
			dir.push_back(nd);
			x += dx[nd];
			y += dy[nd];
			if (x < 0 || x > 100 || y < 0 || y > 100) continue;
			map[x][y] = 1;
		}
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		sol( x, y, d, g);
	}

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				result++;
	cout << result;
	return 0;
}
