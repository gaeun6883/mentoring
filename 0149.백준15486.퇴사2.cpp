//mentoring 2022.2.21
//다이나믹 프로그래밍

#include <iostream>
#define MAX 1500003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t[MAX], p[MAX], dp[MAX] = { 0, }, result = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];

	for (int i = 1; i <= n + 1; i++) {
		result = max(result, dp[i]);
		if (i + t[i] <= n + 1)
			dp[i + t[i]] = max(result + p[i], dp[i + t[i]]);
	}

	cout << result;
	return 0;
}
