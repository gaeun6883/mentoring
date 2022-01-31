//mentoring 105. 2022.1.30
//트리-dfs알고리즘

#include <iostream>
#include <vector>
#include <utility>
#define MAX 10003
using namespace std;

vector<pair<int, int>> node[MAX];//<연결노드, 가중치>
int visited[MAX];
int result = 0, r = 0;

void dfs(int n, int size) {
	if (visited[n]) return;
	visited[n] = 1;
	if (result < size) {
		result = size;
		r = n;
	}

	for (int i = 0; i < node[n].size(); i++)
		dfs(node[n][i].first, size + node[n][i].second);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		visited[i] = 0;

	for (int i = 0; i < n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}

	dfs(1, 0);
	result = 0;
	for (int i = 0; i <= n; i++)
		visited[i] = 0;
	dfs(r, 0);

	cout << result;
	return 0;
}
