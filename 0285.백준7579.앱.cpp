//mentoring 285. 2022.8.2
//dp

#include <iostream>
#define MAX 101
using namespace std;

int n, m, a[MAX], c[MAX], sum = 0;
int dp[MAX][10003];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		sum += c[i];
	}

	for(int i=1; i<=n; i++)
		for (int j = 0; j <= sum; j++) {
			if (j - c[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + a[i]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}

	for(int i=1; i<=sum; i++)
		if (dp[n][i] >= m) {
			cout << i;
			return 0;
		}
}
