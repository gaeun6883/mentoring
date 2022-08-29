//mentoring 312. 2022.8.29
//구현

#include <iostream>
#include <climits>
#define MAX 55
using namespace std;

int n, m,result=INT_MAX;
char map[MAX][MAX];

void sol(int a, int b);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for (int i = 0; i <= n - 8; i++)
		for (int j = 0; j <= m - 8; j++)
			sol(i, j);

	cout << result;
	return 0;
}

void sol(int a, int b) {
	int cnt = 0;
	char c = map[a][b];

	for (int i = a; i < a + 8; i++) {
		for (int j = b; j < b + 8; j++) {
			if (map[i][j] != c) cnt++;

			if (c == 'W') c = 'B';
			else c = 'W';
		}
		if (c == 'W') c = 'B';
		else c = 'W';
	}
	cnt = min(cnt, 64 - cnt);
	result = min(result, cnt);
}
