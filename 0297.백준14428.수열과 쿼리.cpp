//mentoring 297. 2022.8.14
//세그먼트 트리

#include <iostream>
#include <vector>
#include <utility>
#define MAX 100001
#define INF 0x7fff'ffff
using namespace std;

int n,m, arr[MAX];
vector<pair<int, int>> tree;

pair<int, int> init(int left, int right, int node) {
	if (left == right) return tree[node] = { arr[left], left };
	int mid = (left + right) / 2;
	return tree[node] = min(init(left, mid, node * 2),init(mid + 1, right, node * 2 + 1));
};

pair<int, int> query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (nodeLeft > right || nodeRight < left) return { INF,1 };
	if (nodeLeft >= left && right >= nodeRight) return tree[node];
	int mid = (nodeLeft + nodeRight) / 2;
	return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
}

void update(int idx, long long value, int node, int start, int end) {
	if (idx < start || end < idx) return;
	if (start == end) {
		tree[node] = { value,tree[node].second };
		return;
	}
	int mid = (start + end) / 2;
	update(idx, value, node * 2, start, mid);
	update(idx, value, node * 2 + 1, mid + 1, end);
	tree[node] = min(tree[node * 2],tree[node * 2 + 1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	tree.resize(4 * n);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	init(1,n,1);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			update(b, c, 1, 1, n);
		else cout << query(b, c, 1, 1, n).second << "\n";
	}

	return 0;
}
