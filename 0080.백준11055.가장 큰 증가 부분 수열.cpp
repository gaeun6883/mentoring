//mentoring 79. 2022.1.20
//다이나믹 프로그래밍-LIP 알고리즘

#include <iostream>
#define MAX 1003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[MAX], dp[MAX];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	dp[0] = 1;
	int result = dp[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++)
			if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		result = max(result, dp[i]);
	}
	cout << result;
}
