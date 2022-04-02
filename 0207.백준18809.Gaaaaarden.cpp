//mentoring 207. 2022.4.2
//dfs, bfs, 구현

#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#define MAX 55
using namespace std;

int n, m, g, r, map[MAX][MAX], check[MAX][MAX], result=0;
int liquidG, liquidR;
//1:R, 2:G, 3:flower
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 0 , 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs() {
	int board[MAX][MAX];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			board[i][j] = map[i][j];
	queue<pair<int, int>> qR, qG;
	int visitedG[MAX][MAX], visitedR[MAX][MAX];
	memset(visitedG, 0, sizeof(visitedG));
	memset(visitedR, 0, sizeof(visitedR));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (check[i][j] == 1) {
				qR.push({ i, j });
				visitedR[i][j] = 1;
			}
			else if (check[i][j] == 2) {
				qG.push({ i, j });
				visitedG[i][j] = 1;
			}

	int cnt = 0;
	while (!qR.empty() || !qG.empty()) {
		int sizeR = qR.size();
		for (int i = 0; i < sizeR; i++) {
			int x = qR.front().first;
			int y = qR.front().second;
			qR.pop();
			if (board[x][y] == 3) continue;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (visitedR[nx][ny] || board[nx][ny] == 0 || board[nx][ny] == 3) continue;
				if (visitedG[nx][ny] && visitedG[nx][ny] != visitedR[x][y] + 1) continue;
				else if (visitedG[nx][ny] && visitedG[nx][ny] == visitedR[x][y] + 1) {
					board[nx][ny] = 3;
					cnt++;
					visitedR[nx][ny] = visitedR[x][y] + 1;
					continue;
				}
				visitedR[nx][ny] = visitedR[x][y] + 1;
				qR.push({ nx, ny });
			}
		}
		int sizeG = qG.size();
		for (int i = 0; i < sizeG; i++) {
			int x = qG.front().first;
			int y = qG.front().second;
			qG.pop();
			if (board[x][y] == 3) continue;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (visitedG[nx][ny] || board[nx][ny] == 0 || board[nx][ny] == 3) continue;
				if (visitedR[nx][ny] && visitedR[nx][ny] != visitedG[x][y] + 1) continue;
				else if (visitedR[nx][ny] && visitedR[nx][ny] == visitedG[x][y] + 1) {
					board[nx][ny] = 3;
					cnt++;
					visitedG[nx][ny] = visitedG[x][y] + 1;
					continue;
				}
				visitedG[nx][ny] = visitedG[x][y] + 1;
				qG.push({ nx, ny });
			}
		}
	}

	result = max(result, cnt);
}
void dfs(int idx, int cnt) {
	if (cnt == g + r) {
		bfs();
		return;
	}
	for (int i = idx + 1; i < n * m; i++) {
		int x = i / m;
		int y = i % m;
		if (map[x][y] == 2) {
			if (liquidR) {
				liquidR--;
				check[x][y] = 1;
				dfs(i, cnt + 1);
				check[x][y] = 0;
				liquidR++;
			}
			if (liquidG) {
				liquidG--;
				check[x][y] = 2;
				dfs(i, cnt + 1);
				check[x][y] = 0;
				liquidG++;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	liquidG = g;
	liquidR = r;

	dfs(-1, 0);
	cout << result;
	return 0;
}
