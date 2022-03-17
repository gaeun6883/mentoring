//mentoring 191. 2022.3.16
//다익스트라 최소거리 알고리즘

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#define MAX 55
using namespace std;

vector<pair<int,int>> v[MAX];
int d[MAX];

void Dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    d[1] = 0;
    while (!q.empty()){
        int cost = q.top().first;
        int cur = q.top().second;
        q.pop();
        for (int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i].first;
            int n_cost = v[cur][i].second;
            if (d[next] > cost + n_cost){
                d[next] = cost + n_cost;
                q.push({d[next], next});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K){
    int answer = 0;
    for (int i = 0; i < road.size(); i++){
        int house1 = road[i][0];
        int house2 = road[i][1];
        int cost = road[i][2];
        v[house1].push_back({house2, cost});
        v[house2].push_back({house1, cost});
    }
    for(int i=0; i<=MAX; i++)
        d[i]=INT_MAX;

    Dijkstra();

    for (int i = 1; i <= N; i++)
        if (d[i] <= K)
            answer++;

    return answer;
}
