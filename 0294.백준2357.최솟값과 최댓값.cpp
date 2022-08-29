//mentoring 294. 2022.8.11
//세그먼트 트리

#include <iostream>
#define MAX 100001
#define INF 2000000000
using namespace std;

int n, m;
long long arr[MAX], minTree[4 * MAX], maxTree[4 * MAX];

long long init_min(int left, int right, int node) {
    if (left == right) return minTree[node] = arr[left];
    int mid = (left + right) / 2;
    return minTree[node] = min(init_min(left, mid, node * 2), init_min(mid + 1, right, node * 2 + 1));
}
long long init_max(int left, int right, int node) {
    if (left == right) return maxTree[node] = arr[left];
    int mid = (left + right) / 2;
    return maxTree[node] = max(init_max(left, mid, node * 2), init_max(mid + 1, right, node * 2 + 1));
}

long long query_min(int left, int right, int node, int nodeLeft, int nodeRight) {
    if (nodeLeft > right || nodeRight < left) return INF;
    if (nodeLeft >= left && right >= nodeRight) return minTree[node];
    int mid = (nodeLeft + nodeRight) / 2;
    return min(query_min(left, right, node * 2, nodeLeft, mid), query_min(left, right, node * 2 + 1, mid + 1, nodeRight));
}
long long query_max(int left, int right, int node, int nodeLeft, int nodeRight) {
    if (nodeLeft > right || nodeRight < left) return 0;
    if (nodeLeft >= left && right >= nodeRight) return maxTree[node];
    int mid = (nodeLeft + nodeRight) / 2;
    return max(query_max(left, right, node * 2, nodeLeft, mid), query_max(left, right, node * 2 + 1, mid + 1, nodeRight));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    init_min(1, n, 1);
    init_max(1, n, 1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cout << query_min(a, b, 1, 1, n) << " "<<query_max(a,b,1,1,n)<<"\n";
    }
	return 0;
}
