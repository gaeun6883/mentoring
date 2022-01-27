//mentoring 88. 2022.1.24
//다이나믹 프로그래밍-LIS알고리즘

#include <iostream>
#include <vector>
#define MAX 1004
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[MAX], front_dp[MAX], back_dp[MAX];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++) {//�պ���
		front_dp[i] = 1;
		for (int j = 1; j <= i; j++)
			if (arr[j] < arr[i])
				front_dp[i] = max(front_dp[i], front_dp[j] + 1);
	}

	for (int i = n; i > 0; i--) {//�ں���
		back_dp[i] = 1;
		for (int j = n; j >= i; j--)
			if (arr[j] < arr[i])
				back_dp[i] = max(back_dp[i], back_dp[j] + 1);
	}

	int result = 0;
	for (int i = 1; i <= n; i++)
		result = max(result, front_dp[i] + back_dp[i]-1);
	cout << result;
}
