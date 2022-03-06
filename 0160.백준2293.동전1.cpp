//mentoring 160. 2022.2.27
//다이나믹 프로그래밍

#include <iostream>
#include <string>
#define MAX 10003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, arr[MAX], dp[MAX] = { 1 };
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
		for (int j = arr[i]; j <= k; j++)
			dp[j] = dp[j] + dp[j - arr[i]];

	cout << dp[k];
	return 0;
}
