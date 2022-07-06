//mentoring 254. 2022.6.28
//bfs & 구현

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <cstring>
#define MAX 22
using namespace std;

int n, m, fuel, map[MAX][MAX], visited[MAX][MAX];
int curX=0, curY=0, length = INT_MAX, go;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

typedef struct customer {
	int startX, startY;
	int endX, endY;
};
vector<customer> cmd;

int bfs(int a, int b);
void shortest();
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> fuel;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];

	cin >> curX >> curY;
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cmd.push_back({ a,b,c,d });
	}

	while (!cmd.empty()){
		length = INT_MAX;
		shortest();
		if (fuel<go){
			fuel = -1;
			break;
		}
		fuel = fuel - length;

		curX = cmd[go].startX;
		curY = cmd[go].startY;

		length = INT_MAX;
		length = bfs(cmd[go].endX, cmd[go].endY);

		if (length == -1||length>fuel){
			fuel = -1;
			break;
		}
		fuel = fuel - length;
		curX = cmd[go].endX;
		curY = cmd[go].endY;
		cmd.erase(cmd.begin() + go);

		fuel += length * 2;
	}

	cout << fuel << endl;
	return 0;
}

int bfs(int a, int b) {
	memset(visited, 0, sizeof(visited));
	if (curX == a && curY == b) return 0;

	visited[curX][curY] = 1;
	queue<pair<int, int> > q;
	q.push({curX, curY});

	int result = 0;
	while (!q.empty()){
		int s = q.size();
		for (int i = 0; i < s; i++){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; dir++){
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
				if (visited[nx][ny] == 1||map[nx][ny] == 1) continue;
				if (nx == a && ny == b) return result + 1;
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
		result++;
	}
	return -1;
}

void shortest() {
	for (int i = 0; i < cmd.size(); i++){
		int sum = bfs(cmd[i].startX, cmd[i].startY);
		if (sum == -1) return;
		else if (length > sum){
			length = sum;
			go = i;
		}
		else if (length == sum){
			if (cmd[go].startX > cmd[i].startX)
				go = i;
			else if (cmd[go].startX == cmd[i].startX)
				if (cmd[go].startY > cmd[i].startY)
					go = i;
		}
	}
}
