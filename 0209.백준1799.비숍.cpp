//mentoring 2022.4.4
//dfs, bfs

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define MAX 11
using namespace std;

int n, map[MAX][MAX], shadow[MAX][MAX], check[MAX][MAX], answer[2] = { 0,0 };
int dx[4] = { -1,1,1,-1 };
int dy[4] = { -1,-1,1,1 };

bool checkBFS(int x, int y) {
	for (int i = 0; i < 4; i++){
		int nx = x;
		int ny = y;
		while (true){
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
			if (check[nx][ny] == true) return false;
			nx = nx + dx[i];
			ny = ny + dy[i];
		}
	}
	return true;
}

void dfs(int idx, int cnt, int color) {
	answer[color]=max(answer[color], cnt);

	for (int i = idx + 1; i < n * n; i++) {
		int x = i / n;
		int y = i % n;
		if (shadow[x][y] != color || map[x][y] == 0) continue;
		if (checkBFS(x, y)) {
			check[x][y] = 1;
			dfs(i, cnt + 1, color);
			check[x][y] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (i % 2 == j % 2)
				shadow[i][j] = 1;
			else shadow[i][j]=0;
		}

	dfs(-1, 0, 1);
	dfs(-1, 0, 0);

	cout << answer[0] + answer[1];
	return 0;
}
