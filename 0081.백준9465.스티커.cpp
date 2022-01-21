//mentoring 81. 2022.1.21
//다이나믹 프로그래밍

#include <iostream>
#define MAX 100004
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, dp[2][MAX] = { 0, }, arr[2][MAX] = { 0, };
		cin >> n;
		for (int x = 0; x <2; x++)
			for (int y = 1; y <= n; y++)
				cin >> arr[x][y];

		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];
		for (int i = 2; i <= n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}

		cout << max(dp[0][n], dp[1][n])<<"\n";
	}
	return 0;
}
