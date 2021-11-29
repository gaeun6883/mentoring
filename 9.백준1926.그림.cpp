//mentoring 9. 2021.11.11
//que-bfs, <utility>_pair의 사용

#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define MAX 502
#define X first
#define Y second

int x, y;
int board[MAX][MAX];
int vis[MAX][MAX] = { 0, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int BFS(int i, int j);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> x >> y;
	queue<pair<int, int>> q;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cin >> board[i][j];

	int group=0;
	int maxArea=0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (board[i][j] == 1 && vis[i][j] == 0) {
				int area = BFS(i, j);
				maxArea = max(maxArea, area);
				group++;
			}
		}
	}
	cout << group << "\n";
	cout << maxArea;
}

int BFS(int i, int j) {
	int area = 1;
	queue<pair<int, int>> Q;
	Q.push({ i,j });
	board[i][j] = 0;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;

			Q.push({ nx,ny });
			board[nx][ny] = 0;
			vis[nx][ny] = 1;
			area++;
		}
	}
	return area;
}
