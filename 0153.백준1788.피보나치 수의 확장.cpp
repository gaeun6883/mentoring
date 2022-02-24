//mentoring 153. 2022.2.23
//다이나믹 프로그래밍

#include <iostream>
#define MAX 1000001
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, state = 1, dp[MAX] = { 0,1 };
	cin >> n;
	if (n < 0) {
		n *= -1;
		if (n % 2 == 0)
			state = -1;
	}
	else if (n == 0)
		state = 0;

	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;

	cout << state << "\n" << dp[n];
	return 0;
}
