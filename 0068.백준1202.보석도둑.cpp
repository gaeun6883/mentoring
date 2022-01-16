//mentoring 68. 2022.1.15
//priority que

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> info;//<무게, 가격>
	vector<int> bagW(k);
	for (int i = 0; i < n; i++) {
		int w, p;
		cin >> w >> p;
		info.push_back({ w,p });
	}
	for (int i = 0; i < k; i++)
		cin >> bagW[i];

	sort(info.begin(), info.end());
	sort(bagW.begin(), bagW.end());

	long long answer = 0, idx=0;//int 오류
	priority_queue<int> ans;
	for (int i = 0; i < k; i++) {
		int bag_weight = bagW[i];
		while (idx < n && info[idx].first <= bag_weight)
			ans.push(info[idx++].second);
		if (!ans.empty()) {
			answer += ans.top();
			ans.pop();
		}
	}
	cout << answer;
	return 0;
}
