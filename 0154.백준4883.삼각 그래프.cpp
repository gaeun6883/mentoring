//mentoring 154. 2022.2.24
//다이나믹 프로그래밍

#include <iostream>
#include <climits>
#include <algorithm>
#define MAX 100003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;
	while (true) {
		int n, arr[MAX][3], dp[MAX][3];
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++)
				cin >> arr[i][j];

		cnt++;
		dp[0][0] = INT_MAX;
		dp[0][1] = arr[0][1];
		dp[0][2] = dp[0][1] + arr[0][2];
		for (int i = 1; i < n; i++) {
			dp[i][0] = arr[i][0] + min(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = arr[i][1] + min({ dp[i][0], dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
			dp[i][2] = arr[i][2] + min({ dp[i][1], dp[i - 1][1], dp[i - 1][2] });
		}

		cout << cnt << ". " << dp[n - 1][1] << "\n";
	}
	return 0;
}
