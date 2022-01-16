//mentoring 70. 2022.1.16
//다이나믹 프로그래밍

#include <iostream>
#include <algorithm>
#define MAX 10003
using namespace std;

int main() {
	int n;
	cin >> n;
	int p[MAX], dp[MAX] = {0, };
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		dp[i] = p[i];
	}
	for (int i = 2; i <= n; i++)
		for(int j=1; j<=i; j++)
			dp[i] = max(dp[i], dp[i - j] + p[j]);
	cout << dp[n];
}
