//mentoring 151. 2022.2.21
//다이나믹 프로그래밍

#include <iostream>
#define MAX  1000003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		long long n, dp[MAX] = { 0,1,2,4 };
		cin >> n;
		for (int i = 4; i <= n; i++)
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
		cout << dp[n] << '\n';
	}
	return 0;
}
