//mentoring 250. 2022.6.24
//구현

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v;//<����, ��>
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		v.push_back({ from, to });
	}
	sort(v.begin(), v.end());

	int sum = 0;
	int start = v[0].first, end = v[0].second;
	for (int i = 1; i < n; i++) {
		if (v[i].first <= end)
			end = max(end, v[i].second);
		else {
			sum += end - start;
			start = v[i].first;
			end = v[i].second;
		}
	}
	sum += end - start;
	cout << sum;
	return 0;
}
