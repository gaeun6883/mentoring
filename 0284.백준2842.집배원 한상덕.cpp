//mentoring 284. 2022.8.1
//bfs&구현

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <climits>
#include <utility>
#define MAX 55
using namespace std;

int n, startX, startY, dest, h[MAX][MAX], visited[MAX][MAX], result = INT_MAX;
char map[MAX][MAX];
vector<int> stress;
int dx[8] = { 1,0,-1,0,1,1,-1,-1 };
int dy[8] = { 0,1,0,-1,1,-1,-1,1 };

bool bfs(int l, int r);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'P') {
				startX = i;
				startY = j;
			}
			if (map[i][j] == 'K') dest++;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> h[i][j];
			stress.push_back(h[i][j]);
		}
	sort(stress.begin(), stress.end());
	stress.erase(unique(stress.begin(), stress.end()), stress.end());

	int l = 0, r = 0;
	while (l < stress.size() && r < stress.size()) {
		memset(visited, 0, sizeof(visited));
		if (bfs(l, r)) l++;
		else r++;
	}
	cout << result;
	return 0;
}

bool bfs(int l, int r) {
	queue<pair<int, int>> q;
	if (stress[l] <= h[startX][startY] && h[startX][startY] <= stress[r]) {
		q.push({ startX,startY });
		visited[startX][startY] = 1;
	}

	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
				if (stress[l] <= h[nx][ny] && h[nx][ny] <= stress[r]) {
					if (map[nx][ny] == 'K')
						cnt++;
					q.push({ nx,ny });
					visited[nx][ny] = 1;
				}
			}
		}
	}

	if (cnt == dest) {
		result = min(result, stress[r] - stress[l]);
		return true;
	}
	return false;
}
