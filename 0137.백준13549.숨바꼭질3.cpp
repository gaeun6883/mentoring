//mentoring 137. 2022.2.15
//bfs

#include <iostream>
#include <deque>
#include <utility>
#define MAX 1000003
using namespace std;

int n, k, cnt[MAX] = { -1, };
int d[2] = { 2, 1 };

void bfs() {
	deque<int> q;
	q.push_back(n);
	cnt[n] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop_front();
		if (x == k)
			return;
		int nx = x * d[0];
		if (nx >= 0 && nx < MAX && cnt[nx] == -1) {
			q.push_front(nx);
			cnt[nx] = cnt[x];
		}
		nx = x - d[1];
		if (nx >= 0 && nx < MAX && cnt[nx] == -1) {
			q.push_back(nx);
			cnt[nx] = cnt[x] + 1;
		}
		nx = x + d[1];
		if (nx >= 0 && nx < MAX && cnt[nx] == -1) {
			q.push_back(nx);
			cnt[nx] = cnt[x] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < MAX; i++)
		cnt[i] = -1;

	bfs();

	cout << cnt[k];
	return 0;
}
