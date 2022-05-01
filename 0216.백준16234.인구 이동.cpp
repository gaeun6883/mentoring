//mentoring 216. 2022.4.28
//bfs

#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#define MAX 53
using namespace std;

int n, l, r, country[MAX][MAX], population[MAX][MAX], visited[MAX][MAX];
int m = 0, result = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int a, int b);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r;
    int cnt = 1;//country ID
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            country[i][j] = cnt++;
            cin >> population[i][j];
        }

    while (true) {
        memset(visited, 0, sizeof(visited));
        m = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!visited[i][j])
                    bfs(i, j);
        if (m == 0) break;
        result++;
    }

    cout << result;
    return 0;
}

void bfs(int a, int b) {
    queue<pair<pair<int, int>, int>> q;
    queue<pair<pair<int, int>, int>> board;
    q.push({ {a, b}, country[a][b] });
    board.push({ {a, b}, country[a][b] });

    visited[a][b] = country[a][b];
    int cnt = 1;
    int total = population[a][b];

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int num = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
            if (!visited[nx][ny])
                if ((abs(population[x][y] - population[nx][ny]) >= l) && (abs(population[x][y] - population[nx][ny]) <= r)) {
                    cnt++;
                    m++;
                    total += population[nx][ny];
                    q.push({ { nx, ny }, num });
                    board.push({ {nx, ny}, num });
                    visited[nx][ny] = num;
                }
        }
    }

    while (!board.empty()) {
        int x = board.front().first.first;
        int y = board.front().first.second;
        board.pop();
        population[x][y] = total / cnt;
    }
}
