//mentoring 152. 2022.2.23
//다이나믹 프로그래밍

#include <iostream>
#define MAX 1000001
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, dp[MAX] = { 0,1,2 };
	cin >> n;

	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;

	cout << dp[n];
	return 0;
}
