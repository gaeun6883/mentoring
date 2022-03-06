//mentoring 163. 2022.2.28
//다이나믹 프로그래밍

#include <iostream>
#define MAX 2003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, arr[MAX], dp[MAX][MAX] = { 0, };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		dp[i][i] = 1;
		if (i != 1 && arr[i - 1] == arr[i])
			dp[i - 1][i] = 1;
	}

	for (int i = 2; i <= n - 1; i++)
		for (int j = 1; i + j <= n; j++)
			if (arr[j] == arr[i + j] && dp[j + 1][i + j - 1] == 1)
				dp[j][i + j] = 1;

	cin >> m;
	while (m--) {
		int start, end;
		cin >> start >> end;
		cout << dp[start][end] << "\n";
	}
	return 0;
}
