//mentoring 208. 2022.4.3
//dfs

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10
using namespace std;

int n, m, arr[MAX];
vector<int> v;
void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	int tmp = 0;
	for (int i = idx; i < n; i++) {
		if (tmp != v[i]) {
			arr[cnt] = v[i];
			tmp = v[i];
			dfs(i, cnt + 1);
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
	dfs(0, 0);

	return 0;
}
