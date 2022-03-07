//mentoring 169. 2022.3.4
//dfs

#include <string>
#include <vector>
using namespace std;

bool check[8]={false,};
vector<vector<int>> v;
int answer = -1;

void dfs(int n, int cnt){
    for(int i=0;i<v.size();i++)
        if(!check[i] && v[i][0]<=n){
            check[i]=true;
            dfs(n-v[i][1],cnt+1);
            check[i]=false;
        }
    answer = max(answer,cnt);
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    v = dungeons;
    dfs(k,0);
    return answer;
}
