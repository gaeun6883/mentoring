//mentoring 150. 2022.2.22
//다이나믹 프로그래밍

#include <iostream>
#include <vector>
#define MAX 41
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, vip[MAX] = { 0,0 }, dp[MAX] = { 1,1,2 };
	cin >> n >> m;
	for (int i = 2; i <= m+1; i++)
		cin >> vip[i];
	vip[m + 2] = n + 1;

	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	int result = 1;
	for (int i = 2; i <= m + 2; i++) {
		int section=vip[i]-vip[i-1]-1;
		result *= dp[section];
	}
	cout << result;
	return 0;
}
