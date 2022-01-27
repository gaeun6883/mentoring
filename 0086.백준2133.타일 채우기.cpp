//mentoring 86. 2022.1.23
//다이나믹 프로그래밍

#include <iostream>
#define MAX 35
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n % 2 == 1) {
		cout << 0;
		return 0;
	}

	int dp[MAX] = { 1,0,3 };
	for (int i = 4; i <= n; i+=2) {
		dp[i] = dp[i - 2] * dp[2];
		for (int j = 4; i - j >= 0; j += 2)
			dp[i] += dp[i - j] * 2;
	}
	cout << dp[n];
	return 0;
}
