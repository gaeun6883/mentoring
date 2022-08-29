//mentoring 307. 2022.8.24
//Greedy

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, l,result;
vector<pair<int, int>> v;
int ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());
	int cnt = 0, cover = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].first > cover)
			cover = v[i].first;
		if(v[i].second>=cover)
			while (v[i].second > cover) {
				cover += l;
				cnt++;
			}
	}
	cout << cnt;
	return 0;
}
