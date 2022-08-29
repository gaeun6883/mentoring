//mentoring 306. 2022.8.23
//bfs

#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

int n, p,cnt=-1,visited[MAX];
vector<int> g[MAX];

void bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < g[x].size(); i++) {
			int nx = g[x][i];
			if (!visited[nx]) {
				visited[nx] = 1;
				q.push(nx);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p;
	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	bfs();
	cout << cnt;
	return 0;
}
