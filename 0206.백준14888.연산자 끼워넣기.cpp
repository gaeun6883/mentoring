//mentoring 206. 2022.4.1
//dfs

#include <iostream>
#include <climits>
#define MAX 12
using namespace std;

int n, a[MAX], op[4], resultMax=INT_MIN, resultMin=INT_MAX;
int calc(int a, int b, int op);

void dfs(int idx, int result) {
	if (idx == n) {
		resultMax = max(resultMax, result);
		resultMin = min(resultMin, result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			int next = calc(result, a[idx], i);
			dfs(idx + 1, next);
			op[i]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];

	dfs(1, a[0]);
	cout << resultMax <<"\n" << resultMin;
	return 0;
}

int calc(int a, int b, int op) {
	if (op == 0) return a + b;
	if (op == 1) return a - b;
	if (op == 2) return a * b;
	else return a / b;
}
