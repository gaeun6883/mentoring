//mentoring 74. 2022.1.18
//다이나믹 프로그래밍

#include <iostream>
#define MAX 105
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	long long dp[MAX] = { 0,1,1 };
	for (int i = 3; i < MAX; i++)
		dp[i] = dp[i - 2] + dp[i - 3];
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}
