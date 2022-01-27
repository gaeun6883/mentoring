//mentoring 84. 2022.1.22
//다이나믹 프로그래밍

#include <iostream>
#define MAX 103
#define mod 1000000000
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	long long dp[MAX][11];
	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= 9; j++)
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1] % mod;
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1] % mod;
			else
				dp[i][j] = (dp[i - 1][j + 1]+ dp[i - 1][j - 1]) % mod;

	long long result = 0;
	for (int i = 0; i < 10; i++)
		result += dp[n][i];
	cout << result % mod;
}
