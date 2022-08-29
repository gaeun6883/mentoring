//mentoring 305. 2022.8.22
//벨만 포드 알고리즘

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#define MAX 505
using namespace std;

typedef struct node {
	int from, to, cost;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m, w;
		cin >> n >> m >> w;

		vector<node> v;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v.push_back({ a,b,c });
			v.push_back({ b,a,c });
		}
		for (int i = 0; i < w; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v.push_back({ a,b,-c });
		}

		int d[MAX];
		for (int i = 0; i < MAX; i++)
			d[i] = -1;
		d[1] = 0;

		for (int i = 1; i < n; i++)
			for (int j = 0; j < v.size(); j++) {
				int start = v[j].from;
				int end = v[j].to;
				int dist = v[j].cost;
				d[end] = min(d[end], d[start] + dist);
			}

		bool state = false;
		for (int i = 0; i < v.size(); i++) {
			int start = v[i].from;
			int end = v[i].to;
			int dist = v[i].cost;
			if (d[end] > d[start] + dist) {
				state = true;
				break;
			}
		}

		if (state) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
