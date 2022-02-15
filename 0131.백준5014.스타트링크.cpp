//mentoring 131. 2022.2.12
//bfs

#include <iostream>
#include <queue>
#define MAX 1000003
using namespace std;

int f, s, g, u, d;
int dy[2], cnt[MAX] = { -1, };
bool state = true;

void bfs() {
	queue<int> q;
	cnt[s] = 0;
	q.push(s);

	while (!q.empty()) {
		int y = q.front();
		q.pop();
		if (y == g)
			return;
		for (int dir = 0; dir < 2; dir++) {
			int ny = y + dy[dir];
			if (ny<1 || ny>f) continue;
			if (cnt[ny] == -1) {
				cnt[ny] = cnt[y] + 1;
				q.push(ny);
			}
		}
	}
	state = false;
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> f >> s >> g >> u >> d;

	for (int i = 1; i <= f; i++)
		cnt[i] = -1;
	dy[0] = u;
	dy[1] = d * (-1);

	bfs();

	if (!state)
		cout << "use the stairs";
	else cout << cnt[g];
	return 0;
}
