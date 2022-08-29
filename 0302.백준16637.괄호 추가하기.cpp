//mentoring 302. 2022.8.19
//dfs

#include <iostream>
#include <climits>
#define MAX 22
using namespace std;

int n, check[MAX], result=INT_MIN;
string s;

int calc(int a, int b, char op);
void dfs(int idx, int value) {
	if (idx > n-1) {
		result = max(result, value);
		return;
	}

	char op;
	if (idx == 0) op = '+';
	else op = s[idx - 1];

	if (idx + 2 < n) {
		int tmp = calc(s[idx]-'0', s[idx + 2]-'0', s[idx + 1]);
		dfs(idx + 4, calc(value, tmp, op));
	}
	dfs(idx + 2, calc(value,s[idx]-'0', op));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	dfs(0,0);
	cout << result;
	return 0;
}

int calc(int a, int b, char op) {
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
}
