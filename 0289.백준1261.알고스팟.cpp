//mentoring 289. 2022.8.6
//bfs

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define MAX 101
using namespace std;

int n, m, map[MAX][MAX], visited[MAX][MAX], d[MAX][MAX];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

void bfs();
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j + 1] = s[j] - '0';
			d[i][j + 1] = INT_MAX;
		}
	}

	bfs();
	cout << d[n][m];
	return 0;
}
void bfs() {
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	d[1][1] = 0;
	while(!q.empty()) {
		int x=q.front().first;
		int y= q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > m)continue;
			if(map[nx][ny]==1){
				if(d[nx][ny]>d[x][y]+1){
					d[nx][ny]=d[x][y]+1;
					q.push({nx,ny});
				}
			}
			else {//map=0
				if (d[nx][ny] > d[x][y]) {
					d[nx][ny] = d[x][y];
					q.push({ nx, ny });
				}
			}
		}
	}
}
