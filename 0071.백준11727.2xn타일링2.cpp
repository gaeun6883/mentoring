//mentoring 71. 2022.1.16
//다이나믹 프로그래밍

#include <iostream>
#include <algorithm>
#define MAX 10003
using namespace std;

int main() {
	int n;
	cin >> n;
	int dp[MAX] = { 0, };
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++)
			dp[i] =(dp[i-1]+2*dp[i-2])%10007;
	cout << dp[n];
}
