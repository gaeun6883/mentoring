//mentoring 10. 2021.11.12
//que_bfs 응용(미로찾기)

#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define MAX 502
#define X first
#define Y second

int N, M;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int maze[MAX][MAX];
int vis[MAX][MAX] = { 0, };

int findpath();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			int n = line[j] - '0';
			maze[i][j] = n;
		}
	}

	int result = findpath();
	cout << result;
	return 0;
}

int findpath() {
	int count[MAX][MAX] = { 1, };
	queue<pair<int, int>> Q;
	vis[0][0] = 1;
	Q.push({ 0,0 });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			if (cur.X == N - 1 && cur.Y == M - 1)
				break;
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx >= 0 && ny >= 0 && nx < N && ny<M && maze[nx][ny] == 1 && vis[nx][ny] == 0) {
				Q.push({ nx,ny });
				vis[nx][ny] = 1;
				maze[nx][ny] = 0;
				count[nx][ny] = count[cur.X][cur.Y] + 1;
			}
		}
	}
	return count[N-1][M-1];
}
