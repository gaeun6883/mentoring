//mentoring 218. 2022.4.30
//bfs

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#define MAX 55
using namespace std;

int n, m, map[MAX][MAX], result = 0;
vector<pair<int, int>> comand;
vector<pair<int, int>> cloud;
int dx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

void solution(int idx) {
	int dir = comand[idx].first;
	int pow = comand[idx].second;
	for (int i = 0; i < cloud.size(); i++) {
		int x = cloud[i].first;
		int y = cloud[i].second;
		int nx = x + dx[dir] * pow;
		int ny = y + dy[dir] * pow;
		while (!(nx >= 1 && nx <= n))
			if (nx < 1) nx += n;
			else if (nx > n) nx -= n;
		while (!(ny >= 1 && ny <= n))
			if (ny < 1) ny += n;
			else if (ny > n) ny -= n;
		cloud[i].first = nx;
		cloud[i].second = ny;
	}

	for (int i = 0; i < cloud.size(); i++)
		map[cloud[i].first][cloud[i].second ]++;

	for (int i = 0; i < cloud.size(); i++) {
		int x = cloud[i].first;
		int y = cloud[i].second;
		dir = 2;
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
				if (map[nx][ny] >= 1)
					map[x][y]++;
			dir += 2;
		}
	}

	vector<pair<int, int>> tmp;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (map[i][j] >= 2)
				if (find(cloud.begin(), cloud.end(), make_pair( i, j )) == cloud.end()) {
					tmp.push_back({i, j});
					map[i][j] -= 2;
				}
	cloud.clear();
	cloud = tmp;
	tmp.clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	memset(map, 0, sizeof(map));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		comand.push_back({ a,b });
	}
	cloud.push_back({ n, 1 });
	cloud.push_back({ n, 2 });
	cloud.push_back({ n - 1, 1 });
	cloud.push_back({ n - 1, 2 });

	for (int i = 0; i < m; i++)
		solution(i);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			result += map[i][j];
	cout << result;
	return 0;
}
