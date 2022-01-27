//mentoring 83. 2022.1.22
//다이나믹 프로그래밍

#include <iostream>
#define MAX 1003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, dp[MAX][10] = { 0, };
	cin >> n;
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int x = 2; x <= n; x++)
		for (int y = 0; y < 10; y++)
			for (int i = y; i < 10; i++)
				dp[x][y] += dp[x - 1][i] % 10007;

	long long result = 0;
	for (int i = 0; i < 10; i++)
		result += dp[n][i];
	cout << result%10007;
	return 0;
}
