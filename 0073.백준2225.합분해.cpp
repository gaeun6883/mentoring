//mentoring 73. 2022.1.17
//다이나믹 프로그래밍

#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin >> n >> k;
	long long dp[201][201] = { 0, };
	for (int i = 0; i <= n; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= k; i++)
		for (int j = 0; j <= n; j++)
			for (int l = 0; l <= j; l++)
				dp[i][j] = (dp[i][j] + dp[i - 1][l]) % 1000000000;
	cout << dp[k][n];
}
