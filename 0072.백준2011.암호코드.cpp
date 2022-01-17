//mentoring 72. 2022.1.17
//다이나믹 프로그래밍

#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long dp[5003] = { 1,1 };
	string s;
	cin >> s;

	if (s[0] == '0') {
		cout << 0;
		return 0;
	}
	for (int i = 2; i <= s.size(); i++) {
		if (s[i-1] > '0')
			dp[i] = dp[i - 1] % 1000000;

		int n = ((s[i - 2] - '0') * 10) + (s[i-1] - '0');
		if (10 <= n && n <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
	}
	cout << dp[s.size()];
	return 0;
}
