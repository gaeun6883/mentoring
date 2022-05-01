//mentoring 220. 2022.5.2
//dfs

#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int n, m, h, map[12][32], visited[12][32],result = INT_MAX;

bool check();
void dfs(int idx, int cnt) {
	if (cnt >= 4) return;
	if (check()) {
		result = min(result, cnt);
		return;
	}

	for (int i = idx; i <= h; i++)
		for (int j = 1; j < n; j++){
			if (visited[j][i]||visited[j - 1][i]||visited[j + 1][i]) continue;
			visited[j][i] = 1;
			dfs(i, cnt + 1);
			visited[j][i] = 0;
		}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(visited, 0, sizeof(visited));
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		visited[b][a] = 1;
	}

	dfs(1, 0);
	if (result == INT_MAX) result = -1;
	cout << result;
	return 0;
}

bool check() {
	for (int i = 1; i <= n; i++){
		int num = i;
		for (int j = 1; j <= h; j++)
			if (visited[num][j]) num++;
			else if (visited[num - 1][j]) num--;
		if (num != i) return false;
	}
	return true;
}
