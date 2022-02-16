//mentoring 138. 2022.2.16
//bfs-지나온 경로 출력

#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#define MAX 1000003
using namespace std;

int n, k, cnt[MAX] = { -1, }, visited[MAX];
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
			cnt[nx] = cnt[x] + 1;
			visited[nx] = x;
		}
		nx = x - d[1];
		if (nx >= 0 && nx < MAX && cnt[nx] == -1) {
			q.push_back(nx);
			cnt[nx] = cnt[x] + 1;
			visited[nx] = x;
		}
		nx = x + d[1];
		if (nx >= 0 && nx < MAX && cnt[nx] == -1) {
			q.push_back(nx);
			cnt[nx] = cnt[x] + 1;
			visited[nx] = x;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < MAX; i++) {
		cnt[i] = -1;
		visited[i] = -1;
	}

	bfs();

	cout << cnt[k] << "\n";
	vector<int> v;
	int idx = k;
	while (idx != n) {
		v.insert(v.begin(), idx);
		idx = visited[idx];
	}
	v.insert(v.begin(), n);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}
