//mentoring 279. 2022.7.25
//kruskal algorithm

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100003
using namespace std;

long long n, m, parent[MAX],d[MAX];

long long search(long long num) {
	if (parent[num] == num) return num;

	int tmp = parent[num];
	parent[num] = search(parent[num]);
	d[num] += d[tmp];
	return parent[num];
}

void exclam(int a, int b, int w) {
	int x = search(a);
	int y = search(b);
	if (x == y) return;
	d[x] = d[a] - d[b] + w;
	parent[x] = y;
}
bool question(int a, int b) {
	int x = search(a);
	int y = search(b);
	if (x == y) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		for (int i = 0; i <= n; i++) {
			parent[i] = i;
			d[i] = 0;
		}

		for (int i = 0; i < m; i++) {
			char op;
			cin >> op;
			if (op == '!') {
				int a, b, c;
				cin >> a >> b >> c;
				exclam(a, b, c);
			}
			else {
				int a, b;
				cin >> a >> b;
				if (question(a, b)) cout << d[a] - d[b] << "\n";
				else cout << "UNKNOWN\n";
			}
		}
	}
	return 0;
}
