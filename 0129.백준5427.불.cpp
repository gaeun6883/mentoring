//mentoring 129. 2022.2.11
//bfs

#include <iostream>
#include <queue>
#include <utility>
#define MAX 1003
using namespace std;

int w, h, result=0;
char map[MAX][MAX];
int s[MAX][MAX], f[MAX][MAX];
bool state;
queue<pair<int, int>> sang;
queue<pair<int, int>> fire;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void reset();
void fire_bfs();
void sang_bfs();

void bfs() {
	fire_bfs();
	sang_bfs();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> w >> h;
		reset();
		for (int i = 0; i < h; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < w; j++){
				map[i][j]=str[j];
				if (map[i][j] == '@') {
					sang.push({ i, j });
					s[i][j] = 0;
				}
				if (map[i][j] == '*'){
					fire.push({ i, j });
					f[i][j] = 0;
				}
			}
		}

		bfs();

		if (!state)
			cout << "IMPOSSIBLE" << "\n";
	}
}

void reset() {
	state = false;
	while (!sang.empty())
		sang.pop();
	while (!fire.empty())
		fire.pop();
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			s[i][j] = -1;
			f[i][j] = -1;
		}
}

void fire_bfs() {
	while (!fire.empty()) {
		int x = fire.front().first;
		int y = fire.front().second;
		fire.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (map[nx][ny] == '#' || f[nx][ny] != -1) continue;
			f[nx][ny] = f[x][y] + 1;
			fire.push({ nx,ny });
		}
	}
}

void sang_bfs() {
	while (!sang.empty()) {
		int x = sang.front().first;
		int y = sang.front().second;
		sang.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
				cout << s[x][y] + 1 << "\n";
				state = true;
				break;
			}
			if (map[nx][ny] == '#' || map[nx][ny] == '*') continue;
			if (s[nx][ny] != -1) continue;
			if ((s[x][y] + 1 >= f[nx][ny]) && f[nx][ny] != -1) continue;
			s[nx][ny] = s[x][y] + 1;
			sang.push({ nx,ny });
		}
		if (state) break;
	}
}
