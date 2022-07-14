//mentoring 265.7.12
//kruskal algorithm

#include <string>
#include <vector>
#include <queue> 
#include <utility>
#define MAX 105
using namespace std;

int visited[MAX];
vector<pair<int, int>> g[MAX];

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0; i<costs.size(); i++){
        int a=costs[i][0];
        int b=costs[i][1];
        int cost=costs[i][2];
        g[a].push_back({b,cost});
        g[b].push_back({a,cost});
    }

    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> q;
    for(int i=0; i<g[0].size(); i++)
        q.push({g[0][i].second, g[0][i].first});

    visited[0]=1;
    while(!q.empty()){
        int cost=q.top().first;
        int cur=q.top().second;
        q.pop();
        if(!visited[cur]){
            visited[cur]=1;
            answer+=cost;
            for(int i=0; i<g[cur].size(); i++){
                int next=g[cur][i].first;
                int ncost=g[cur][i].second;
                if(!visited[next])
                    q.push({ncost, next});
            }
        }
    }
    return answer;
}
