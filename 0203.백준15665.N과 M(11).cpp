//mentoring 203. 2022.3.29
//dfs

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8
using namespace std;

int n, m, arr[MAX];
vector<int> v;

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (tmp!=v[i]) {
			arr[cnt] = v[i];
			tmp = v[i];
			dfs(cnt + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	dfs(0);

	return 0;
}
