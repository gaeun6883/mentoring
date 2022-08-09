//mentoring 282. 2022.7.30
//bfs

#include <iostream>
#include <queue>
#include <cstring>
#define MAX 11
using namespace std;

int n, m, visited[MAX][MAX][MAX][MAX],result = 0;
int rX, rY, bX, bY;
typedef struct location {
	int redX, redY, blueX, blueY;
};
char map[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int bfs();
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				rX = i;
				rY = j;
			}
			if (map[i][j] == 'B') {
				bX = i;
				bY = j;
			}
		}
	cout << bfs;
	return 0;
}

int bfs() {
	queue<location> q;
	q.push({ rX,rY,bX,bY });
	memset(visited, 0, sizeof(visited));
	visited[rX][rY][bX][bY] = 1;

	while(!q.empty()) {
		int t = q.size();
		while (t--) {
			int s = q.size();
			int redX = q.front().redX;
			int redY = q.front().redY;
			int blueX = q.front().blueX;
			int blueY = q.front().blueY;
			q.pop();

			if (map[redX][redY] == 'O' && map[redX][redY] != map[blueX][blueY])
				return result;

			for (int dir = 0; dir < 4; dir++) {
				int rnx = redX;
				int rny = redY;
				int bnx = blueX;
				int bny = blueY;

				//move red,blue
				while (map[rnx + dx[dir]][rny + dy[dir]] != '#' && map[rnx][rny] != 'O') {
					rnx += dx[dir];
					rny += dy[dir];
				}
				while (map[bnx + dx[dir]][bny + dy[dir]] != '#' && map[bnx][bny] != 'O') {
					bnx += dx[dir];
					bny += dy[dir];
				}

				if(rnx==bnx&&rny==bny)
					if(map[rnx][bny]!='O')
						if (abs(rnx - redX) + abs(rny - redY) < abs(bnx - blueX) + abs(bny - blueY)) {
							bnx -= dx[dir];
							bny -= dy[dir];
						}
						else {
							rnx -= dx[dir];
							rny -= dy[dir];
						}

				if (!visited[rnx][rny][bnx][bny]) {
					q.push({ rnx,rny,bnx,bny });
					visited[rnx][rny][bnx][bny] = 1;
				}
			}
		}
		if (result >= 10)
			return -1;
		result++;
	}
	return -1;
}
