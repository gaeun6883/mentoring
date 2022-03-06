//mentoring 161. 2022.2.27
//다이나믹 프로그래밍

#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	int dp[MAX][MAX];
	for(int i=1; i<=a.length(); i++)
		for(int j=1; j<=b.length(); j++)
			if(a[i-1]==b[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

	cout << dp[a.length()][b.length()];
	return 0;
}
