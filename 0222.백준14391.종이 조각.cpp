//mentoring 222. 2022.5.4
//dfs & 구현

#include <iostream>
#define MAX 5
using namespace std;

int n, m, map[MAX][MAX], visited[MAX][MAX], result = 0;
int sum();
void dfs(int idx, int cnt) {
	if (idx == n) {
		result = max(result, sum());
		return;
	}
	if (cnt == m) {
		dfs(idx + 1, 0);
		return;
	}

	visited[idx][cnt] = 1;
	dfs(idx, cnt + 1);
	visited[idx][cnt] = 0;
	dfs(idx, cnt + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			map[i][j] = s[j]-'0';
	}

	dfs(0, 0);
	cout << result;
	return 0;
}

int sum() {
	int total = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++)
            if (visited[i][j])
                sum = (sum * 10) + map[i][j];
			else {
				total += sum;
				sum = 0;
			}
        total += sum;
    }

    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (!visited[i][j])
                sum = (sum * 10) + map[i][j];
			else {
				total += sum;
				sum = 0;
			}
        total += sum;
    }
    return total;
}
