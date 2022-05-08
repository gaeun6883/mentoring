//mentoring 221. 2022.5.3
//graph

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 10001
using namespace std;

int v, e, a, b, c;
long long result;
bool visit[MAX];
vector<pair<int, int>> g[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}

	q.push({ 0,1 });
	while (!q.empty()) {
		int weight = q.top().first;
		int node = q.top().second;

		q.pop();
		if (visit[node]) continue;
		visit[node] = true;
		result += weight;
		for (int i = 0; i < g[node].size(); i++) {
			int nNode = g[node][i].first;
			int nWeight = g[node][i].second;
			q.push(make_pair(nWeight, nNode));
		}
	}
	cout << result;
}
