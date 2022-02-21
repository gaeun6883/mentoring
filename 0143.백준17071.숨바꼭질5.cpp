//mentoring 143. 2022.2.18
//bfs
//본래 숨바꼭질시리즈 코드는 cnt배열을 만들어 짰으나 남동생의 위치가 계속 바뀌는 것이 신경쓰여 큐 안에 집어넣음.

#include <iostream>
#include <queue>
#include <utility>
#define MAX 500003
using namespace std;

int n, k, visited[2][MAX];
int d[3] = { -1,1 ,2 };

int bfs() {
    queue<pair<int, int>> q;
    q.push({ n, 0 });
    visited[0][n] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int t = q.front().second;
        q.pop();
        int bro = k + t * (t + 1) / 2;

        if (bro > 500000) return -1;
        if (visited[t % 2][bro]) return t;

        int nx;
        for (int dir = 0; dir < 3; ++dir) {
            if (dir < 2) nx = x + d[dir];
            else nx = x * d[dir];
            if (nx < 0 || nx > 500000) continue;
            if (!visited[(t+1) % 2][nx]) {
                visited[(t+1) % 2][nx] = 1;
                q.push({ nx, t+1 });
            }
        }
    }
    return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
    for (int i = 0; i < MAX; i++)
        visited[0][i] = visited[1][i] = 0;

	cout << bfs();
	return 0;
}
