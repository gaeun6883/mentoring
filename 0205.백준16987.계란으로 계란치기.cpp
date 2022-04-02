//mentoring 205. 2022.3.31
//dfs

#include <iostream>
#include <algorithm>
using namespace std;

int n, s[8], w[8], result = 0;

void dfs(int idx) {
	if (idx >= n) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (s[i] <= 0)
				cnt++;
		result = max(result, cnt);
		return;
	}

	if (s[idx] <= 0)
		dfs(idx + 1);
	else {
		bool check = false;
		for (int i = 0; i < n; i++) {
			if (idx == i || s[i] <= 0) continue;
			s[i] -= w[idx];
			s[idx] -= w[i];
			check = true;
			dfs(idx + 1);
			s[i] += w[idx];
			s[idx] += w[i];
		}
		if (!check) dfs(n);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i] >> w[i];

	dfs(0);
	cout << result;
	return 0;
}
