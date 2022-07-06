//mentoring 249. 2022.6.23
//priority_queue

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair <int, int>> v;
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		v.push_back({ s, t });
	}
	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(v[0].second);
	for (int i = 1; i < n; i++) {
		if (pq.top() <= v[i].first)
			pq.pop();
		pq.push(v[i].second);
	}
	cout << pq.size() << endl;
	return 0;
}
