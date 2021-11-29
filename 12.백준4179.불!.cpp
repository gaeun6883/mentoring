//mentoring 12. 2021.11.14
//bfs응용, 불과 J 두가지 큐의 활용과 비교
//다시풀기

#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define MAX 1001
#define X first
#define Y first

//초기 코드
/*int R, C;
char maze[MAX][MAX];
int firemap[MAX][MAX];
int cnt[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> J;
	queue<pair<int, int>> fire;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> maze[i][j];
			cnt[i][j] = -1;
			firemap[i][j] = 99999;
			if (maze[i][j] == 'J') {
				J.push({ i,j });
				cnt[i][j] = 0;
			}
			if (maze[i][j] == 'F') {
				fire.push({ i, j });
				firemap[i][j] = 0;
			}
		}
	}

	while (!fire.empty()) {
		pair<int, int> F = fire.front();
		fire.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = F.X + dx[dir];
			int ny = F.Y + dy[dir];
			if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
				if (maze[nx][ny] != '#'&& firemap[nx][ny] == 99999) {
					fire.push({ nx, ny });
					firemap[nx][ny] = firemap[F.X][F.Y] + 1;
				}
			}
		}
	}

	int result = -1;
	while (true) {
		pair<int, int> cur = J.front();
		fire.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx <0 || nx >= R || ny < 0 || ny > C)
				result = cnt[cur.X][cur.Y]+1;

			if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
				if (maze[nx][ny] == '.' && firemap[nx][ny] > cnt[cur.X][cur.Y]+1) {//���� �ƴϰ� �ҵ� ���ٸ�,
					J.push({ nx,ny });
					cnt[nx][ny] = cnt[cur.X][cur.Y] + 1;
				}
			}
		}
	}

	if (result == -1)
		cout << "IMPOSSIBLE";
	else
		cout << result;

	return 0;
}*/
