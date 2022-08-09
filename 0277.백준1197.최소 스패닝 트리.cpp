//mentoring 277. 2022.7.24
//kruskal algorithm

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10004
using namespace std;

struct  node{
	int u, v, w;
	bool operator<(const node& b) {
		return w < b.w;
	}
};
vector<node> g;
int v, e, parent[MAX], result = 0;

int search(int num) {
	if (parent[num] == num) return num;
	return parent[num] = search(parent[num]);
}

bool sol(int a, int b) {
	int x = search(a);
	int y = search(b);
	if (x != y) {
		parent[x] = y;
		return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	for (int i = 1; i <= v; i++)
		parent[i] = i;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g.push_back({ a,b,c });
	}
	sort(g.begin(), g.end());

	for (int i = 0; i < e; i++)
		if (sol(g[i].u, g[i].v))
			result += g[i].w;

	cout << result;
	return 0;
}
