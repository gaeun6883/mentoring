//mentoring 275. 2022.7.22
//위상정렬

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define MAX 503
using namespace std;

int n, t[MAX], seq[MAX], result[MAX];
vector<int> v[MAX];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		while (true) {
			int num;
			cin >> num;
			if (num == -1) break;
			v[num].push_back(i);
			seq[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (seq[i] == 0) {
			q.push(i);
			result[i] = t[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			seq[next]--;
			result[next] = max(result[next], result[cur] + t[next]);
			if (seq[next] == 0)
				q.push(next);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << result[i] << "\n";
	return 0;
}
