//mentoring 281. 2022.7.29
//플로이드

#include <iostream>
#include <cstring>
#define MAX 505
#define LIMIT 987654321
using namespace std;

int n, m, h[MAX][MAX], result = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			h[i][j] = LIMIT;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		h[a][b] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				h[i][j] = min(h[i][j], h[i][k] + h[k][j]);

	for (int i = 1; i <= n; i++){
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			if (h[i][j] != LIMIT || h[j][i] != LIMIT)
				cnt++;
		if (cnt == n - 1) result++;
	}

	cout << result;
	return 0;
}
