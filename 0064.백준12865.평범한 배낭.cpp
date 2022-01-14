//mentoring 64. 2022.1.13
//다이나믹 프로그래밍-그리디로 풀면 안됨

#include <iostream>
#include <algorithm>
#define MAX 1000005
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	int w[MAX], v[MAX],dp[103][MAX];
	for (int i = 1; i <= N; i++)
		cin >> w[i] >> v[i];
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= K; j++){
			if (j >= w[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][K] << endl;
}
