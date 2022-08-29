//mentoring 304. 2022.8.20
//다익스트라 알고리즘

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#define MAX 1000
using namespace std;

int n, e, v1, v2, d[MAX];
long long r1 = 0, r2 = 0;
vector<pair<int, int>> v[MAX];
int Dijkstra(int a, int b);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
    cin >> v1 >> v2;

    r1 += Dijkstra(1, v1);
    r1 += Dijkstra(v1,v2);
    r1 += Dijkstra(v2, n);

    r2 += Dijkstra(1, v2);
    r2 += Dijkstra(v2, v1);
    r2 += Dijkstra(v1, n);

    long long result = min(r1, r2);
    if (result >= INT_MAX) cout<<"-1";
    else cout << result;
    return 0;
}

int Dijkstra(int start, int end) {
    for (int i = 0; i < MAX; i++)
        d[i] = INT_MAX;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({ 0, start });
    d[start] = 0;
    while (!q.empty()) {
        int cost = q.top().first;
        int cur = q.top().second;
        q.pop();
        if (d[cur] < cost) continue;
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int n_cost = v[cur][i].second;
            if (d[next] > cost + n_cost) {
                d[next] = cost + n_cost;
                q.push({ d[next], next });
            }
        }
    }
    return d[end];
}
