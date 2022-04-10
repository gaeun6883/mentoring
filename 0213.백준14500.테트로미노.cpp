//mentoring 213. 2022.4.8
//dfs

#include <iostream>
#include <cstring>
#define MAX 503
using namespace std;

int n, m, map[MAX][MAX], visited[MAX][MAX], result = 0;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void dfs(int x, int y, int sum, int cnt) {
    if (cnt == 4) {
        result = max(result, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (!visited[nx][ny]) {
            visited[nx][ny] = 1;
            dfs(nx, ny, sum + map[nx][ny], cnt + 1);
            visited[nx][ny] = 0;
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //memset(visited, 0, sizeof(visited));//->�ð��ʰ�
            visited[i][j] = 1;
            dfs(i, j, map[i][j], 1);
            //��,��,��,��
            if (i - 1 >= 0 && j + 2 < m) {
                sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1];
                result = max(result, sum);
            }
            if (i +1<n && j + 2 < m) {
                sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
                result = max(result, sum);
            }
            if (i + 2 < n && j + 1 < m) {
                sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
                result = max(result, sum);
            }
            if (i - 1 >= 0 && i + 1 < n && j + 1 < m) {
                sum = map[i][j] + map[i-1][j + 1] + map[i][j + 1] + map[i+ 1][j + 1];
                result = max(result, sum);
            }
            visited[i][j] = 0;
        }
    }
    cout << result;
	return 0;
}
