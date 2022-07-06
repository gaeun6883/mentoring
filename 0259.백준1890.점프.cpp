//mentoring 259. 2022.7.3
//dynamic programming

#include <iostream>
#define MAX 103
using namespace std;

int n, arr[MAX][MAX];
long long dp[MAX][MAX] = { 0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) continue;
			int tmp = arr[i][j];
			if (tmp + i < n) dp[tmp + i][j] += dp[i][j];
			if (tmp + j < n) dp[i][tmp + j] += dp[i][j];
		}
	}
	cout << dp[n - 1][n - 1];
	return 0;
}
