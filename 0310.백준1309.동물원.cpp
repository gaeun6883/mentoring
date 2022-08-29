//mentoring 310. 2022.8.27
//dynamic programming

#include <iostream>
#define MAX 100003
#define MOD 9901;
using namespace std;

int n, dp[MAX][3];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	for (int i = 2; i <= n; i++) {

		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = dp[i - 1][0] + dp[i - 1][2] % MOD;
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1] % MOD;

	}
	cout<<(dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
}
