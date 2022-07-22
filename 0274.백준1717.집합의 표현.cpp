//mentoring 274. 2022.7.21
//분리 집합

#include <iostream>
#define MAX 1000001
using namespace std;

int n, m, arr[MAX];

int search(int n) {
	if (n == arr[n]) return n;
	return arr[n] = search(arr[n]);
}

void zero(int a, int b) {
	int x = search(a);
	int y = search(b);
	if (x != y)
		arr[y]=x;
}

bool one(int a, int b) {
	int x = search(a);
	int y = search(b);
	if (x == y) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		arr[i] = i;

	for (int i = 0; i < m; i++) {
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0) zero(a, b);
		else {
			if (one(a,b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
