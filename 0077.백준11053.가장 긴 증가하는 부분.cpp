//mentoring 77. 2022.1.19
//다이나믹 프로그래밍-LIP 알고리즘

#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[1003], dp[1003];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = 1;
	int result = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		result = max(result, dp[i]);
	}
	cout << result;
}
