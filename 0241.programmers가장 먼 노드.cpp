//mentoring 2022.5.24
//다잌스트라 알고리즘 

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> map(n + 1, -1);
    map[1] = 0;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < edge.size(); i++) {
        g[edge[i][0]].push_back(edge[i][1]);
        g[edge[i][1]].push_back(edge[i][0]);
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int node : g[cur])
            if (map[node] == -1) {
                map[node] = map[cur] + 1;
                q.push(node);
            }
    }

    int maxN = *max_element(map.begin(), map.end());
    for (int i = 0; i < map.size(); i++)
        if (map[i] == maxN)
            answer++;
    return answer;
}
