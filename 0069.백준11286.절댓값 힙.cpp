//mentoring 68. 2022.1.15
//priority que

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int abs(int n) {
	if (n < 0)
		n *= -1;
	return n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> >> q;//<절댓값, 원래값>
	vector<int> answer;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num != 0)
			q.push({ abs(num), num });
		else {
			if (q.empty()) {
				answer.push_back(0);
				continue;
			}
			answer.push_back(q.top().second);
			q.pop();
		}
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << "\n";
	return 0;
}
