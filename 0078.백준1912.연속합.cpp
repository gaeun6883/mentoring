//mentoring 78. 2022.1.20
//다이나믹 프로그래밍

#include <iostream>
#define MAX 100004
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[MAX], dp[MAX];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int result=dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		result = max(result, dp[i]);
	}
	cout << result;
}
