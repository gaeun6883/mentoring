//mentoring 290. 2022.8.7
//다익스트라 알고리즘

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAX 300001
#define T 501
using namespace std;

int n, m, result, d[MAX];
char map[T][T];
bool state;
vector<pair<int, int>> g[MAX];

void dijkstra();
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '/') {
				g[i * T + j].push_back({ (i + 1) * T + (j + 1),1 });
				g[(i + 1) * T + (j + 1)].push_back({ i * T + j,1 });
				g[(i + 1) * T + j].push_back({ i *T + (j + 1),0 });
				g[i * T + (j + 1)].push_back({ (i + 1) * T + j,0 });
			}
			else {
				g[i * T + j].push_back({ (i + 1) * T + (j + 1),0 });
				g[(i + 1) * T + (j + 1)].push_back({ i * T + j,0 });
				g[(i + 1) * T + j].push_back({ i * T + (j + 1),1 });
				g[i * T + (j + 1)].push_back({ (i + 1) * T + j,1 });
			}
		}

	dijkstra();
	if (d[n*T+m]==INT_MAX) cout << "NO SOLUTION";
	else cout << d[n * T + m];
	return 0;
}

void dijkstra() {
	for (int i = 0; i <= MAX; i++)
		d[i] = INT_MAX;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, 0 });
	d[0] = 0;
	while (!q.empty()) {
		int cost = q.top().first;
		int cur = q.top().second;
		q.pop();
		if (d[cur] < cost) continue;
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i].first;
			int n_cost = g[cur][i].second;
			if (d[next] > cost + n_cost) {
				d[next] = cost + n_cost;
				q.push({ d[next], next });
			}
		}
	}
}
