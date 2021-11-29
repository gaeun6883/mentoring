//mentoring 11. 2021.11.13
//que_bfs 응용

#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define MAX 502
#define X first
#define Y second

int N, M;
int box[MAX][MAX];
int vis[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			vis[i][j] = -1;
			if (box[i][j] == 1) {
				Q.push({ i,j });
				vis[i][j] = 0;
			}
		}
	}

	while (!Q.empty()) {//bfs
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && vis[nx][ny] == -1 && box[nx][ny] == 0) {
				Q.push({ nx,ny });
				box[nx][ny] = 1;
				vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			result = max(result, vis[i][j]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (box[i][j] == 0 && vis[i][j] == -1)
				result = -1;

	cout << result;
	return 0;
}
