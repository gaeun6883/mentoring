//mentoring 148. 2022.2.21
//다이나믹 프로그래밍

#include <iostream>
#define MAX 20
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t[MAX], p[MAX], dp[MAX] = { 0, };
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];

	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1], dp[i]);
		if (i + t[i] - 1 <= n)
			dp[i + t[i] - 1] = max(dp[i + t[i] - 1], dp[i - 1] + p[i]);
	}
	cout<<dp[n];
	return 0;
}
