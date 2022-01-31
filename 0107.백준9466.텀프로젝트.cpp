//mentoring 107. 2022.1.31
//dfs알고리즘

#include <iostream>
#define MAX 1000003
using namespace std;

int arr[MAX], visited_1[MAX], visited_2[MAX];
int cnt;

void dfs(int n) {
	int next = arr[n];
	visited_1[n] = 1;

	if (!visited_1[next])
		dfs(next);
	else if (!visited_2[next]) {
		for (int i = next; i != n; i = arr[i])
			cnt++;
		cnt++;
	}
	visited_2[n] = 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			visited_1[i] = 0;
			visited_2[i] = 0;
		}

		cnt = 0;
		for (int i = 1; i <= n; i++)
			if (!visited_1[i])
				dfs(i);

		cout << n - cnt << "\n";
	}
	return 0;
}
