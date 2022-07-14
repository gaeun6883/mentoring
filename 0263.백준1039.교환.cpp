//mentoring 263. 2022.7.10
//dfs & dp

#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000003
using namespace std;

int n, k, check[MAX][11], result = -1;

void dfs(string num, int cnt) {
	if (cnt == k) {
		result = max(stoi(num), result);
		return;
	}

	if (check[stoi(num)][cnt]) return;
	check[stoi(num)][cnt] = 1;

	int m = num.size();
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++) {
			if (num[j] == '0' && i == 0) continue;
			swap(num[i], num[j]);
			dfs(num, cnt + 1);
			swap(num[i], num[j]);
		}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	memset(dp, 0, sizeof(dp));

	dfs(to_string(n), 0);
	cout << result;
	return 0;
}
