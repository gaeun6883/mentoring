//mentoring 227. 2022.5.9
//dfs(백트레킹) & bfs

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <climits>
#define MAX 53
using namespace std;

int n, m, map[MAX][MAX],visited[MAX][MAX], check[12], result=INT_MAX;
vector<pair<int, int>> v;
vector<pair<int, int>> virus;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void sol();
void dfs(int idx, int cnt) {
	if (cnt == m) {
		memset(visited, 0, sizeof(visited));
		sol();
		return;
	}

	for (int i = idx; i < v.size(); i++)
		if (!check[i]) {
			check[i] = 1;
			virus.push_back(v[i]);
			dfs(i, cnt + 1);
			virus.pop_back();
			check[i] = 0;
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				v.push_back({ i,j });
		}

	dfs(0, 0);

	if (result == INT_MAX) result = -1;
	cout << result;
	return 0;
}

void sol() {
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		int x = virus[i].first;
		int y = virus[i].second;
		q.push({ x,y });
		visited[x][y] = 1;
	}

	int cnt = 0;
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (!visited[nx][ny] && map[nx][ny] != 1) {
					visited[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
		}
		if (!q.empty()) cnt++;
	}

	for (int i = 0; i <n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j] && map[i][j] != 1) return;
	result = min(result, cnt);
}
