//mentoring 99. 2022.1.27
//DFS

#include <iostream>
#define MAX 1003
using namespace std;

int cnt=0;
int map[MAX], visited[MAX];

void dfs(int n){
	if (!visited[n]) {
		visited[n] = 1;
		dfs(map[n]);
	}
	else cnt++;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		for (int i = 0; i <= n; i++)
			visited[i] = 0;
		for (int i = 1; i <= n; i++) {
			int idx;
			cin >> idx;
			map[i] = idx;
		}

		cnt = 0;
		for (int i = 1; i <= n; i++)
			if (!visited[i])
				dfs(i);
		cout << cnt << "\n";
	}
	return 0;
}
