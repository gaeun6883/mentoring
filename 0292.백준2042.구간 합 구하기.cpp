//mentoring 292. 2022.8.9
//세그먼트 트리

#include <iostream>
using namespace std;

long long arr[1000006];
long long tree[4000006];

long long init(long long node, long long start, long long end) {
    if (start == end) return tree[node] = arr[start];
    long long mid = (start + end) / 2;
    long long left = init(node * 2, start, mid);
    long long right = init(node * 2 + 1, mid + 1, end);
    return tree[node] = left + right;
}

long long sum(long long node, long long start, long long end, long long left, long long right) {
    if (start > right || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    long long mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(long long start, long long end, long long node, long long index, long long dif) {
    if (index < start || index > end) return;
    tree[node] += dif;
    if (start == end) return;
    long long mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    init(1, 0, n - 1);
    for (long long i = 0; i < m+k; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            long long dif = c - arr[b - 1];
            arr[b - 1] = c;
            update(0, n - 1, 1, b - 1, dif);
        }
        else
            cout<< sum(1, 0, n - 1, b - 1, c - 1)<<"\n";
    }
}
