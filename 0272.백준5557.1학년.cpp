//mentoring 272. 2022.7.19
//다이나믹 프로그래밍

#include <iostream>
#define MAX 103
using namespace std;

long long n, arr[MAX], dp[MAX][22];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

    dp[1][arr[1]]++;
    for (int i = 2; i < n; i++)
        for (int j = 0; j <= 20; j++)
            if (dp[i - 1][j]) {
                if (j + arr[i] <= 20)   dp[i][j + arr[i]] += dp[i - 1][j];
                if (j - arr[i] >= 0)    dp[i][j - arr[i]] += dp[i - 1][j];
            }

    cout << dp[n - 1][arr[n]];
	return 0;
}
