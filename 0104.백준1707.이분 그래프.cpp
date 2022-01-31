//mentoring 104. 2022.1.29
//bfs알고리즘

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAX 20003
using namespace std;

int v, e;
vector<int> g[MAX];
int visited[MAX];

void bfs(int n) {
	queue<int> Q;
	int group = 1;
	visited[n] = group;
	Q.push(n);

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		if(visited[cur])
			if (visited[cur] == 1) group = 2;
			else group = 1;

		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i];
			if (!visited[next]) {
				visited[next] = group;
				Q.push(next);
			}
		}
	}
}

bool right() {
	for (int i = 1; i <= v; i++)
		for (int j = 0; j < g[i].size(); j++) {
			int next = g[i][j];
			if (visited[i] == visited[next])
				return false;
		}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K;
	cin >> K;
	for (int k = 0; k < K; k++) {
		cin >> v >> e;

		for (int i = 0; i <= v; i++) {//초기화
			visited[i] = 0;
			g[i].clear();
		}

		for (int i = 0; i < e; i++) {//입력, 무방향성 그래프 생성
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		for (int i = 1; i <= v; i++)//bfs
			if (!visited[i])
				bfs(i);

		if (right())//결과 도출
			cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
