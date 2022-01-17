//mentoring 74. 2022.1.18
//다이나믹 프로그래밍

#include <iostream>
#define MAX 100005
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, dp[MAX]={ 0 };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	}
	cout << dp[n];
}
