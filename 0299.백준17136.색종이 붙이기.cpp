//mentoring 299. 2022.8.16
//백트레킹

#include <iostream>
#include <climits>
#define MAX 12
using namespace std;

int map[MAX][MAX], visit[MAX], result = INT_MAX;

bool check(int a, int b, int c);
void change(int a, int b, int c, int d);
void dfs(int a, int b, int cnt) {
	while (map[a][b] == 0) {
		if (b++ >= 10) {
			if (a++ >= 10) {
				result = min(result, cnt);
				return;
			}
			b = 0;
		}
	}
	if (result <= cnt) return;
	for (int i = 5; i >= 1; i--) {
		if (visit[i] == 5 || a + i > 10 || b + i > 10) continue;
		if (check(a, b, i)) {
			change(a, b, i, 0);
			visit[i]++;
			dfs(a, b, cnt + 1);
			change(a, b, i, 1);
			visit[i]--;
		}
	}
	return;
}

int main() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> map[i][j];
	dfs(0, 0, 0);
	if (result == INT_MAX) cout << -1;
	else cout << result;
}

bool check(int a, int b, int c) {
	for (int i = 0; i < c; i++)
		for (int j = 0; j < c; j++)
			if (map[a + i][b + j] == 0)
				return false;
	return true;
}

void change(int a, int b, int c, int d) {
	for (int i = 0; i < c; i++)
		for (int j = 0; j < c; j++)
			map[a + i][b + j] = d;
}
