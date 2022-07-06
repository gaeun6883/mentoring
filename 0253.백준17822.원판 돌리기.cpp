//mentoring 253. 2022.6.27
//bfs & 구현

#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#define MAX 55
using namespace std;

int n, m, t, arr[MAX][MAX], visited[MAX][MAX], tmp[MAX];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

bool bfs(int a, int b) {
	memset(visited, 0, sizeof(visited));
	queue <pair<int, int>> q;
	q.push({ a, b });
	visited[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx == n) continue;
			if (ny == m) ny = 0;
			else if (ny == -1) ny = m - 1;

			if (!visited[nx][ny] && arr[nx][ny] == arr[x][y]) {
				q.push({ nx, ny });
				visited[nx][ny] = visited[x][y] + 1;
			}

		}
	}

	bool state = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (visited[i][j] > 1)
				state = true;
	if (state)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (visited[i][j])
					arr[i][j] = 0;
	return state;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	while (t--) {
		int x, d, k;
		cin >> x >> d >> k;
		if (d == 1)
			k = m - k;
		for (int i = x - 1; i < n; i += x) {
			for (int a = 0; a < k; a++) {
				for (int j = 0; j < m; j++)
					tmp[j] = arr[i][j];
				for (int j = 1; j < m; j++)
					arr[i][j] = tmp[j - 1];
				arr[i][0] = tmp[m - 1];
			}
		}

		bool state = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!visited[i][j] && arr[i][j] != 0)
					if(bfs(i, j))
						state = true;

		if (!state) {
			double sum = 0, cnt = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (arr[i][j] != 0) {
						sum += arr[i][j];
						cnt++;
					}

			if (cnt > 0) {
				sum /= cnt;
				for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
						if (arr[i][j] != 0) {
							if (sum > arr[i][j]) arr[i][j]++;
							else if (sum < arr[i][j]) arr[i][j]--;
						}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			result += arr[i][j];
	cout << result;
	return 0;
}
