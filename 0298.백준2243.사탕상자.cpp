//mentoring 298. 2022.8.15
//세그먼트 트리

#include <iostream>
#define MAX 1000003
using namespace std;

int n, tree[4 * MAX];

int find(int val, int node, int left, int right) {
    if (left == right) return left;
    int mid = left + (right - left) / 2;
    if (tree[node * 2] < val)
        return find(val - tree[node * 2], 2 * node + 1, mid + 1, right);
    else
        return find(val, 2 * node, left, mid);
}

void update(int idx, long long diff, int node, int start, int end) {
    if (start > idx || end < idx) return;
    tree[node] += diff;
    if (start == end) return;
    int mid = start + (end - start) / 2;
    update(idx, diff, 2 * node, start, mid);
    update(idx, diff, 2 * node + 1, mid + 1, end);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b;
            int candy = find(b, 1, 1, MAX);
            cout << candy << "\n";
            update(candy, -1, 1, 1, MAX);
        }
        else {
            cin >> b >> c;
            update(b, c, 1, 1, MAX);
        }
    }
	return 0;
}
