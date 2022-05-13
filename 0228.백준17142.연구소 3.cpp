//mentoring 228. 5. 10
//dfs(백트레킹) & bfs

#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#define MAX 53
using namespace std;

int n, m, map[MAX][MAX], cnt[MAX][MAX], check[10], result = INT_MAX;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<pair<int, int>> v;

void sol();
void dfs(int idx, int cnt) {
	if (cnt == m) {
		sol();
		return;
	}
	for (int i = idx; i < v.size(); i++)
		if (!check[i]) {
			check[i] = 1;
			dfs(i + 1, cnt + 1);
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
			if (map[i][j] == 2) v.push_back({ i,j });
		}

	dfs(0, 0);
	if (result == INT_MAX) result = -1;
	cout << result;
	return 0;
}

void sol() {
	queue<pair<int, int>> q;
	memset(cnt, -1, sizeof(cnt));
	for (int i = 0; i < v.size(); i++)
		if (check[i]) {
			q.push({ v[i].first, v[i].second });
			cnt[v[i].first][v[i].second] = 0;
		}

	int t = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] != 1 && cnt[nx][ny] == -1) {
				cnt[nx][ny] = cnt[x][y] + 1;
				if (map[nx][ny] == 0)
					t = cnt[nx][ny];
				q.push({ nx,ny });
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (cnt[i][j] == -1 && map[i][j] != 1) return;
	result = min(result, t);
}
