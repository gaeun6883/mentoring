//mentoring 293. 2022.8.10
//세그먼트 트리

#include <iostream>
#include <algorithm>
#define MAX 100001
#define INF 2000000000
using namespace std;

long long arr[MAX], tree[4*MAX];

long long init(int left, int right, int node) {
    if (left == right) return tree[node] = arr[left];
    int mid = (left + right) / 2;
    return tree[node] = min(init(left, mid, node * 2), init(mid + 1, right, node * 2 + 1));
}

long long query(int left, int right, int node, int nodeLeft, int nodeRight){
    if (nodeLeft > right || nodeRight < left) return INF;
    if (nodeLeft >= left && right >= nodeRight) return tree[node];
    int mid = (nodeLeft + nodeRight) / 2;
    return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    init(1, n, 1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b, 1, 1, n) << "\n";
    }
    return 0;
}
