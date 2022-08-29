//mentoring 295. 2022.8.12
//세그먼트 트리

#include <iostream>
#define MAX 1000003
#define MOD 1000000007
using namespace std;

int n, m, k;
long long arr[MAX], tree[4 * MAX];

long long init(int left, int right, int node) {
	if (left == right) return tree[node] = arr[left];
	int mid = (left + right) / 2;
	return tree[node] = (init(left, mid, node * 2)*init(mid + 1, right, node * 2 + 1))%MOD;
}
long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (nodeLeft > right || nodeRight < left) return 1;
	if (nodeLeft >= left && right >= nodeRight) return tree[node];
	int mid = (nodeLeft + nodeRight) / 2;
	return (query(left, right, node * 2, nodeLeft, mid)*query(left, right, node * 2 + 1, mid + 1, nodeRight))%MOD;
}

void update(int idx, long long value, int node, int start, int end){
	if (idx < start || end < idx) return;
	if (start == end){
		tree[node] = value;
		return;
	}
	int mid = (start + end) / 2;
	update(idx, value, node * 2, start, mid);
	update(idx, value,node * 2 + 1, mid + 1, end);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	init(1, n, 1);
	for (int i = 1; i <= m+k; i++) {
		int a, b,c;
		cin >> a >> b >> c;
		if (a == 1) update(b, c, 1, 1, n);
		else cout << query(b, c, 1, 1, n) << "\n";
	}
	return 0;
}
