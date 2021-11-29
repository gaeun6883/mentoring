//mentoring 24. 2021.11.28
//stringstream 사용

#include <string>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second

bool connect[102][102];
bool visited[102];
vector<int> adj_list[102];//인접그래프 리스트 정점

int BFS(int i, int j){
    int sum[2]={1, 1};
    queue<pair<int, int>> q;
    q.push({i, 0});
    q.push({j,1});

    for(int p=0;p<102;p++)
        visited[p]=false;

    visited[i]=true;
    visited[j]=true;

    while(!q.empty()){
        pair<int, int> cur=q.front();
        q.pop();
        for(int i=0; i<adj_list[cur.X].size(); i++){
            int next=adj_list[cur.X][i];
            if(!visited[next]){
                visited[next]=true;
                q.push({next,cur.Y});
                sum[cur.Y]++;
            }
        }
    }
    return abs(sum[0]-sum[1]);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 999;
    for(int i=0; i<wires.size(); i++){
        int start=wires[i][0];
        int end =wires[i][1];
        adj_list[start].push_back(end);
        adj_list[end].push_back(start);
        connect[start][end]=true;
        connect[end][start]=true;
    }//무방향성 그래프 생성

    int Gap=999;
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if(!connect[i][j])
                continue;
            Gap=BFS(i,j);
            answer=min(answer, Gap);
        }
    }
    return answer;
}

//멘토님 코드
/*#include <string>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second

bool connect[102][102];
bool visited[102];
vector<int> adj_list[102];//인접그래프 리스트 정점

int BFS(int i, int j){
    int sum[2]={1, 1};
    queue<pair<int, int>> q;
    q.push({i, 0});
    q.push({j,1});

    for(int p=0;p<102;p++)
        visited[p]=false;

    visited[i]=true;
    visited[j]=true;

    while(!q.empty()){
        pair<int, int> cur=q.front();
        q.pop();
        for(int i=0; i<adj_list[cur.X].size(); i++){
            int next=adj_list[cur.X][i];
            if(!visited[next]){
                visited[next]=true;
                q.push({next,cur.Y});
                sum[cur.Y]++;
            }
        }
    }
    return abs(sum[0]-sum[1]);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 999;
    for(int i=0; i<wires.size(); i++){
        int start=wires[i][0];
        int end =wires[i][1];
        adj_list[start].push_back(end);
        adj_list[end].push_back(start);
        connect[start][end]=true;
        connect[end][start]=true;
    }//무방향성 그래프 생성

    int Gap=999;
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if(!connect[i][j])
                continue;
            Gap=BFS(i,j);
            answer=min(answer, Gap);
        }
    }
    return answer;
}*/
