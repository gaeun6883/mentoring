//mentoring 85. 2022.1.23
//다이나믹 프로그래밍-LIS 알고리즘

#include <iostream>
#include<algorithm>
#include<vector>
#include <utility>
#define MAX 503
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v;//<x,y>
	v.push_back({ 0,0 });
	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v.push_back(pair<int, int>(a, b));
	}
	sort(v.begin(), v.end());

	int dp[MAX] = { 1, };
	int result = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < i; j++)
			if (v[j].second < v[i].second)
				dp[i] = max(dp[i], dp[j] + 1);
		result = max(result, dp[i]);
	}
	cout << n-result+1;
	return 0;
}
