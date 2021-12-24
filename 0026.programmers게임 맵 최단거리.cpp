//mentoring 26. 2021.12.23
//bfs 응용

#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define MAX 103

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool visited[MAX][MAX] = { false, };
int cnt[MAX][MAX] = { -1, };

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();//행
    int m = maps[0].size();//열
    queue<pair<int, int>> q;

    visited[0][0] = true;
    cnt[0][0] = 1;
    q.push({ 0,0 });

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                if (maps[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                    cnt[nx][ny] = cnt[cur.first][cur.second] + 1;
                }
        }
    }
    if (!visited[n - 1][m - 1])
        answer = -1;
    else
        answer = cnt[n - 1][m - 1];
    return answer;
}
