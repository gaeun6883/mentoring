//mentoring 159. 2022.
//다이나믹 프로그래밍

#include <iostream>
#define MAX 1030
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, arr[MAX][MAX], dp[MAX][MAX];
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}

	while (m--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int result = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		cout << result << '\n';
	}
	return 0;
}
