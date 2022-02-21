//mentoring 144. 2022.2.19
//bfs

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define MAX 1503
using namespace std;

int r, c, visited[MAX][MAX];
char map[MAX][MAX];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
vector<pair<int, int>> swan;
queue<pair<int, int>> water;


int bfs(){
    queue<pair<int, int>> q;
    int day = 0;
    q.push(swan[0]);
    visited[swan[0].first][swan[0].second] = 1;
    while (true) {
        queue<pair<int, int>> nq;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= r || ny >= c || visited[nx][ny]) continue;
                else if (swan[1].first == nx && swan[1].second == ny)
                    return day;
                else if (map[nx][ny] == 'X')
                    nq.push({ nx,ny });
                else q.push({ nx,ny });
                visited[nx][ny] = 1;
            }
        }

        q = nq;
        day++;
        int water_s = water.size();
        while (water_s--) {
            int x = water.front().first;
            int y = water.front().second;
            water.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                else if (map[nx][ny] == 'X') {
                    water.push({ nx,ny });
                    map[nx][ny] = '.';
                }
            }
        }
    }
    return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {
                map[i][j] = '.';
				swan.push_back({ i,j });
				water.push({ i,j });
			}
			else if (map[i][j] == '.')
                water.push({ i,j });
		}

	cout << bfs();
    return 0;
}
