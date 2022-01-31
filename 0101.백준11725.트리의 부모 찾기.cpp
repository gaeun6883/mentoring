//mentoring 101. 2022.1.28
//트리, 무방향성 그래프의 bfs알고리즘

#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

vector<int> v[MAX];
int parent[MAX];

void bfs() {
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            if (parent[cur] == next)continue;
            q.push(next);
            parent[next] = cur;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs();

    for (int i = 2; i <= n; i++)
        cout << parent[i] << "\n";
}
