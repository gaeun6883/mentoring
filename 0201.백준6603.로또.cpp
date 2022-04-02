//mentoring 201. 2022.3.27
//백트레킹

#include <iostream>
#include <vector>
#include <cstring>
#define MAX 15
using namespace std;

int k, arr[MAX] = { 0, }, check[MAX] = { 0, };
vector<int> v;

void dfs(int idx, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	int tmp = 0;
	for (int i = idx; i < k; i++) {
		if (!check[i] && v[i] != tmp) {
			check[i] = 1;
			arr[cnt]=v[i];
			tmp = arr[cnt];
			dfs(i, cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		v.clear();
		memset(arr, 0, sizeof(arr));
		memset(check, false, sizeof(check));
		cin >> k;
		if (k == 0) break;
		v.resize(k);
		for (int i = 0; i < k; i++)
			cin >> v[i];
		dfs(0, 0);
		cout << "\n";
	}
	return 0;
}
