//mentoring 76. 2022.1.19
//다이나믹 프로그래밍

#include<iostream>
using namespace std;

long long d[91];
int main() {
	int n;
	cin >> n;

	long long dp[91] = {0,1,1};
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n];
}
