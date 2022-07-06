//mentoring 256. 2022.6.30
//bfs

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAX 102
using namespace std;

int r, c, m;
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };
typedef struct shark {
	int x, y;
	int speed, d, size;
};
int result = 0;
vector<shark> map[MAX][MAX];
void sol(int idx);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> m;
	for (int i = 0; i < m; i++) {
		int a, b, C, d, e;
		cin >> a >> b >> C >> d >> e;
		if (d <= 2) C %= 2 * (r - 1);
		else C %= 2 * (c - 1);
		map[a][b].push_back({ a,b,C,d,e });
	}

	for (int i = 1; i <= c; i++)
		sol(i);

	cout << result;
	return 0;
}

void sol(int idx) {
	for (int i = 1; i <= r; i++)
		if (map[i][idx].size() != 0) {
			result += map[i][idx][0].size;
			map[i][idx].clear();
			break;
		}

	//상어 이동
	vector<shark> tmp;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			for (auto s : map[i][j])
				tmp.push_back(s);
			map[i][j].clear();
		}

	for (auto s : tmp) {
		if (s.d <= 2)
			for (int i = 1; i <= s.speed; i++) {
				if (s.x == 1) s.d = 2;
				else if (s.x == r) s.d = 1;
				s.x += dx[s.d];
				s.y += dy[s.d];
			}
		else
			for (int i = 1; i <= s.speed; i++) {
				if (s.y == 1)
					s.d = 3;
				else if (s.y == c)
					s.d = 4;
				s.x += dx[s.d];
				s.y += dy[s.d];
			}

		if (!map[s.x][s.y].empty()) {
			if (map[s.x][s.y][0].size < s.size) {
				map[s.x][s.y].clear();
				map[s.x][s.y].push_back(s);
			}
		}
		else map[s.x][s.y].push_back(s);
	}
	return;
}
