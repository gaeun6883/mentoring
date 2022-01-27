//mentoring 98. 2022.1.27
//DFS

#include <iostream>
#define MAX 1003
using namespace std;

int map[MAX][MAX];
int check[MAX];
int n, m;

void dfs(int x) {
	check[x] = 1;
	for (int i = 1; i <= n; i++)
		if (map[x][i] && !check[i])
			dfs(i);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			map[i][j] = 0;
			check[j] = 0;
		}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	int result = 0;
	for(int i=1; i<=n; i++)
		if (!check[i]) {
			dfs(i);
			result++;
		}
	cout << result;
}
