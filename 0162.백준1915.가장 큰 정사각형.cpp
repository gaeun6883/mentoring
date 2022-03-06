//mentoring 162. 2022.2.28
//다이나믹 프로그래밍

#include <iostream>
#define MAX 1003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, map[MAX][MAX] = { 0, }, dp[MAX][MAX] = { 0, };
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			map[i][j] = s[j - 1] - '0';
			dp[i][j] = map[i][j];
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (map[i][j]){
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				result = max(result, dp[i][j]);
			}
	cout << result * result;
	return 0;
}
