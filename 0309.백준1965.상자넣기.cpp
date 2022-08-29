//mentoring 209. 2022.8.26
//dynamic programming

#include <iostream>
#define MAX 1001
using namespace std;

int n, arr[MAX], dp[MAX], result = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++)
			if (arr[j] < arr[i] && dp[i] < dp[j]+1)
				dp[i] = dp[j] + 1;
		result = max(result, dp[i]);
	}
	cout << result;
	return 0;
}
