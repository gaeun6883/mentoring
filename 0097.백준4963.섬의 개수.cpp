//mentoring 2022.1.27
//BFS

#include <iostream>
#include <queue>
#include <utility>
#define MAX 53
using namespace std;

int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int map[MAX][MAX], visited[MAX][MAX];
int w, h;

void bfs(int i, int j) {
    queue<pair<int, int>> Q;
    Q.push({ i,j });
    visited[i][j] = 1;

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || ny >= w || nx >= h) continue;
            if (map[nx][ny] && !visited[nx][ny]) {
                Q.push({ nx,ny });
                visited[nx][ny] = 1;
            }
        }
    }
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> w >> h;
        if (w==0 && h==0) break;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
                visited[i][j] = 0;
            }

        int cnt = 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (!visited[i][j] && map[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
        cout << cnt << "\n";
	}
}
