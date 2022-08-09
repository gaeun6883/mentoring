//mentoring 286. 2022.8.3
//다익스트라 알고리즘
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <algorithm>
#define MAX 1001
using namespace std;

int n, m, start, finish, d[MAX];
vector<pair<int, int>> v[MAX];

void Dijkstra();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
    }
    cin >> start >> finish;

    Dijkstra();
    cout << d[finish];
    return 0;
}

void Dijkstra() {
    for (int i = 0; i <= n; i++)
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
}
