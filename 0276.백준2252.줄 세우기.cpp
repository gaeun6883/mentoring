//mentoring 276. 2022.7.23
//위상정렬

#include <iostream>
#include <queue>
#include <vector>
#define MAX 100005
using namespace std;

int n, m, seq[MAX];
vector<int> v[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		seq[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (seq[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < v[cur].size(); i++) {
			int next=v[cur][i];
			seq[next]--;
			if (seq[next] == 0)
				q.push(next);
		}
	}
	return 0;
}
