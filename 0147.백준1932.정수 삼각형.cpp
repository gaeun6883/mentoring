//mentoring 147. 2022.2.20
//다이나믹 프로그래밍

#include <iostream>
#define MAX 503
using namespace std;

int main() {
	int n, dp[MAX][MAX], result=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++) {
			cin >> dp[i][j];

			if (j == 1)
				dp[i][j] = dp[i - 1][j] + dp[i][j];
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + dp[i][j];

			result=max(result, dp[i][j]);
		}
	cout << result;
	return 0;
}
