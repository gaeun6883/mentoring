//mentoring 156. 2022.2.25
//다이나믹 프로그래밍

#include <iostream>
#include <climits>
#define MAX 100003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, arr[103], dp[MAX] = { 0 };
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		dp[i] = INT_MAX;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[arr[i]] = 1;
	}

	for (int i = 1; i <= n; i++)
		for (int j = arr[i]; j <= k; j++)
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);

	if (dp[k] == INT_MAX) cout << "-1";
	else cout << dp[k];
	return 0;
}
