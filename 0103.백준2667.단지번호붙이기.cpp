//mentoring 103. 2022.1.29
//bfs알고리즘

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define MAX 30
using namespace std;

int map[MAX][MAX], visited[MAX][MAX];
int n;
vector<int> v;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int i, int j) {
	queue<pair<int, int>> Q;
	Q.push({ i,j });
	visited[i][j] = 1;

	int area = 1;
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || ny >= n || nx >= n) continue;
			if (map[nx][ny] && !visited[nx][ny]) {
				Q.push({ nx,ny });
				visited[nx][ny] = 1;
				area++;
			}
		}
	}
	v.push_back(area);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j]=s[j]-'0';
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j] && map[i][j])
				bfs(i, j);
	sort(v.begin(), v.end());

	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i]<<"\n";
	return 0;
}
