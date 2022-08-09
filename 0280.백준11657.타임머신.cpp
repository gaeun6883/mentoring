//mentoring 280. 2022.7.28
//벨만 포드 알고리즘

#include <iostream>
#include <vector>
#include <climits>
#define MAX 505
using namespace std;


long long n, m, d[MAX] = { INT_MAX, };
typedef struct node{
	int from, to, cost;
};
vector<node> g;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g.push_back({ a,b,c });
	}

	d[1] = 0;
	for (int i = 0; i <= n; i++)
		d[i] = INT_MAX;

	for(int i=1; i<n; i++)
		for (int j = 0; j < g.size(); j++) {
			int start = g[j].from;
			int end = g[j].to;
			int dist = g[j].cost;
			if (d[start] == INT_MAX) continue;
			d[end] = min(d[end],d[start] + dist);
		}

	for (int i = 0; i < g.size(); i++) {
		int start = g[i].from;
		int end = g[i].to;
		int dist = g[i].cost;

		if (d[start] == INT_MAX) continue;
		if (d[end] > d[start] + dist) {
			cout << -1;
			return 0;
		}
	}
	for (int i = 2; i <= n; i++)
		if (d[i] == INT_MAX) cout << "-1\n";
		else cout << d[i] << "\n";
	return 0;
}
