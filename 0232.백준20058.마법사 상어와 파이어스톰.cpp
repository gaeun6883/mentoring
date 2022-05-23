//mentoring 232. 2022.5.15
//구현 

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#define MAX 70
using namespace std;

int n, q, map[MAX][MAX], visited[MAX][MAX], s;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<pair<int, int>> v;

void rotate(int i, int j, int l);
void check(int i, int j);
int bfs(int i, int j);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	s = pow(2, n);
	for (int i = 1; i <= s; i++)
		for (int j = 1; j <= s; j++)
			cin >> map[i][j];

	while (q--) {
		int l;
		cin >> l;
		int ss = pow(2,l);
		for (int i = 1; i <= s - ss + 1; i += ss)
			for (int j = 1; j <= s - ss + 1; j += ss)
				rotate(i, j, l);

		for (int i = 1; i <= s; i++)
			for (int j = 1; j <= s; j++)
				if (map[i][j] > 0)
					check(i, j);

		for (int i = 0; i < v.size(); i++)
			map[v[i].first][v[i].second]--;
		v.clear();
	}

	int sum = 0, result=0;
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= s; i++)
		for (int j = 1; j <= s; j++) {
			sum += map[i][j];
			if (map[i][j] > 0 && !visited[i][j])
				result = max(result, bfs(i, j));
		}
	cout << sum << "\n" << result;
	return 0;
}

void rotate(int r, int c, int l) {
	int ss = pow(2, l);
	while (ss > 1) {
		vector<int>tmp;
		for (int i = c; i < c + ss; i++)
			tmp.push_back(map[r][i]);

		int j = c + ss- 1;
		for (int i = r; i < r + ss; i++) {
			map[r][j] = map[i][c];
			j--;
		}

		j = r;
		for (int i = c; i < c + ss; i++) {
			map[j][c] = map[r + ss - 1][i];
			j++;
		}

		j = c;
		for (int i = r + ss - 1; i >= r; i--) {
			map[r + ss - 1][j] = map[i][c + ss - 1];
			j++;
		}

		for (int i = r + ss - 1; i >= r; i--) {
			map[i][c + ss - 1] = tmp.back();
			tmp.pop_back();
		}

		ss -= 2;
		r++;
		c++;
	}
}

void check(int r, int c) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (nx <= 0 || nx > s || ny <= 0 || ny > s) continue;
		if (map[nx][ny] > 0) cnt++;
	}

	if (cnt < 3)
		v.push_back({ r,c });
}

int bfs(int a, int b) {
	queue<pair<int, int>>q;
	visited[a][b] = 1;
	q.push({ a, b });
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || nx > s || ny <= 0 || ny > s) continue;
			if (map[nx][ny] > 0 && !visited[nx][ny]) {
				cnt++;
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
	return cnt;
}
