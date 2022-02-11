//mentoring 125. 2022.2.9
//bfs

#include <iostream>
#include <queue>
#include <utility>
#define MAX 53
using namespace std;

int t, m, n, k;
int map[MAX][MAX], visited[MAX][MAX];
int cnt;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i, j });
    visited[i][j] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 && nx >= m && ny < 0 && ny >= n) continue;
            if (!visited[nx][ny] && map[nx][ny]) {
                q.push({ nx, ny });
                visited[nx][ny] = 1;
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
        for(int i=0; i<m; i++)
            for (int j = 0; j < n; j++) {
                map[i][j] = 0;
                visited[i][j] = 0;
            }
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
        }
        cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!visited[i][j] && map[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
        cout << cnt<<"\n";
	}
    return 0;
}
