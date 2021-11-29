//mentoring 13. 2021.11.16
//bfs 응용, 1차원

#include <iostream>
#include <queue>
using namespace std;
#define MAX 100002

int road[MAX] = { -1, };
bool vis[MAX] = { false, };
int dx[3] = { -1,1,2 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int road[MAX] = { 0, };
	int dx[3] = { -1,1,2 };
	int x, k;
	cin >> x >> k;
	queue<int> Q;
	Q.push(x);
	road[x] = 0;
	vis[x] = true;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		if (cur == k)
			break;
		int nx;
		for (int dir = 0; dir < 3; dir++) {
			if (dir == 2)
				nx = cur * dx[dir];
			else
				nx = cur + dx[dir];

			if (nx >= 0 && nx<MAX && vis[nx]== false) {
				Q.push(nx);
				road[nx] = road[cur] + 1;
				vis[nx] = true;
			}
		}
	}

	cout << road[k];
	return 0;
}
