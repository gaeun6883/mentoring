//mentoring 219. 2022.5.1
//bfs & little bit backtracking

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define MAX 22
using namespace std;

int n, map[MAX][MAX], result = 0;
int dx[] = { 0, 1, 1 };
int dy[] = { 1, 0, 1 };

void bfs(){
	queue < pair<pair<int, int>,int>> q;
	q.push({ {0,1},0 });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();

		if (x == n - 1 && y == n - 1) {
			result++;
			continue;
		}

        if (dir == 0 || dir == 1) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                if (!map[nx][ny])
                    q.push({ { nx, ny }, dir });
            nx = x + dx[2];
            ny = y + dy[2];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                if (!map[nx][ny] && !map[x + 1][y] && !map[x][y + 1])
                    q.push({ { nx, ny }, 2 });
        }

        else if (dir == 2){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                if (!map[nx][ny] && !map[x + 1][y] && !map[x][y + 1])
                    q.push({{ nx, ny }, dir});
            for (int i = 0; i < 2; i++){
                nx = x + dx[i];
                ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                    if (!map[nx][ny])
                        q.push({ {nx, ny}, i });
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	bfs();
	cout << result;
	return 0;
}
