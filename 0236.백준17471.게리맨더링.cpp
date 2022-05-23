//mentoring 236. 2022.5.19
//백트레킹 & 구현

#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
#define MAX 11
using namespace std;

int n, map[MAX], visited[MAX], g[MAX][MAX], check[MAX], result = INT_MAX;
int sum0 = 0, sum1 = 0;

void sol(int size);
bool checked(int idx, int state, int target);

void dfs(int idx, int cnt, int s) {
	if (cnt == s) {
		sol(s);
		return;
	}
	for(int i=idx; i<=n; i++)
		if (!check[i]) {
			check[i] = 1;
			dfs(i + 1, cnt + 1, s);
			check[i] = 0;
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> map[i];
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			g[i][b] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
		dfs(1, 0, i);

	if (result == INT_MAX) result = -1;
	cout << result;
	return 0;
}

void sol(int s) {
	int start0 = 0, start1 = 0;
	bool isZero, isOne;
	for (int i = 1; i <= n; i++)
		if (!check[i]) {
			start0 = i;
			break;
		}
	for (int i = 1; i <= n; i++)
		if (check[i]) {
			start1 = i;
			break;
		}

	sum0 = 0;
	isZero = checked(start0, 0, n - s);
	sum1 = 0;
	isOne = checked(start1, 1, s);

	if (isOne && isZero)
		result = min(result, abs(sum0 - sum1));
	return;
}

bool checked(int idx, int state, int target) {
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(idx);
	visited[idx] = 1;
	int cnt = 0;
	while (!q.empty()) {
		int cur = q.front();
		cnt++;
		if (!state) sum0+= map[cur];
		else sum1 += map[cur];
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (g[cur][i]&& !visited[i] && check[i] == state){
				visited[i] = 1;
				q.push(i);
			}
		}
	}
	if (cnt == target) return true;
	else return false;
}
