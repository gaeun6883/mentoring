//mentoring 291. 2022.8.8
//다익스트라 알고리즘

#include <iostream>
#include<vector>
#include<queue>
#include<climits>
#define MAX 10001
using namespace std;

int n, m, x, d[MAX], t[MAX], result;
vector<pair<int, int>> v[MAX];

void Dijkstra(int start);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	for (int i = 1; i <= n; i++) {
		Dijkstra(i);
		t[i] = d[x];
	}
	Dijkstra(x);
	for (int i = 1; i <= n; i++) {
		t[i] += d[i];
		result = max(result, t[i]);
	}

	cout << result;
	return 0;
}

void Dijkstra(int start) {
	for (int i = 0; i <= MAX; i++)
		d[i] = 9876543;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, start });
	d[start] = 0;
	while (!q.empty()) {
		int cost = q.top().first;
		int cur = q.top().second;
		q.pop();
		if (d[cur] < cost) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int n_cost = v[cur][i].second;
			if (d[next] > cost + n_cost) {
				d[next] = cost + n_cost;
				q.push({ d[next], next });
			}
		}
	}
}
