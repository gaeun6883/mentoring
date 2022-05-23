//mentoring 235. 2022.5.18
//백트레킹 & 구현

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define MAX 55
using namespace std;

int n, m, k, map[MAX][MAX], copy_map[MAX][MAX], check[6] = { 0, }, result = INT_MAX;
vector < pair<pair<int, int>, int>> v;
vector<pair<pair<int, int>, int>> arr;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void sol();
void dfs(int cnt) {
	if (cnt == k) {
		sol();
		return;
	}

	for(int i=0; i<k; i++)
		if (!check[i]) {
			check[i] = 1;
			arr[cnt] = v[i];
			dfs(cnt + 1);
			check[i] = 0;
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ {a,b},c });
	}

	arr.resize(k);
	dfs(0);
	cout << result;
	return 0;
}

void sol() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			copy_map[i][j]=map[i][j];

	for (int t= 0; t < k; t++)
		for (int i = 1; i <= arr[t].second; i++) {
			deque<int> tmp;
			int x = arr[t].first.first - i;
			int y = arr[t].first.second - i;
			tmp.push_back(copy_map[x][y]);
			for (int dir = 0; dir < 4; dir++) {
				for (int j = 0; j < 2*i; j++) {
					x += dx[dir];
					y += dy[dir];
					tmp.push_back(copy_map[x][y]);
				}
			}
			tmp.pop_back();
			copy_map[x][y] = tmp.back();
			tmp.pop_back();
			for (int dir = 0; dir < 4; dir++) {
				for (int  j= 0; j < 2*i; j++) {
					if (!tmp.empty()) {
						x += dx[dir];
						y += dy[dir];
						copy_map[x][y] = tmp.front();
						tmp.pop_front();
					}
				}
			}
		}

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= m; j++)
			sum += copy_map[i][j];
		result = min(result, sum);
	}
}
