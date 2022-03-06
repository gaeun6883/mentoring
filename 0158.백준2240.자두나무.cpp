//mentoring 158. 2022.2.26
//다이나믹 프로그래밍

#include <iostream>
#define MAX 1003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t, w, arr[MAX], dp[3][MAX][MAX], result = 0;
	cin >> t >> w;
	for (int i = 1; i <= t; i++)
		cin >> arr[i];

    for (int i = 1; i <= t; i++)
        for (int j = 1; j <= w + 1; j++)
            if (arr[i] == 1) {
                dp[1][i][j] = max(dp[1][i - 1][j] + 1, dp[2][i - 1][j - 1] + 1);
                dp[2][i][j] = max(dp[1][i - 1][j - 1], dp[2][i - 1][j]);
            }
            else {
                if (i == 1 && j == 1) continue;
                dp[1][i][j] = max(dp[2][i - 1][j - 1], dp[1][i - 1][j]);
                dp[2][i][j] = max(dp[1][i - 1][j - 1] + 1, dp[2][i - 1][j] + 1);
            }

    for (int i = 1; i <= w + 1; i++)
        result = max(result, max(dp[1][t][i], dp[2][t][i]));
    cout << result;
    return 0;
}
