//mentoring 265.7.12
//dfs

#include <string>
#include <vector>
#include <algorithm>
#define MAX 100003
using namespace std;

int check[MAX]={0,};
bool state=false;
vector<vector<string>> t;
vector<string> answer, v;


void dfs(string cur, int cnt){
    if(state) return;
    if (cnt == t.size()){
        state=true;
        answer=v;
        return;
    }

    for(int i = 0 ; i < t.size(); i++){
        if (t[i][1] == cur && !check[i]){            
            check[i] = 1;
            v.push_back(cur); 
            dfs(t[i][1], cnt+1);  
            check[i] = 0; 
            v.pop_back(); 
        } 
    }
}

bool cmp(vector<string> a, vector<string> b){
    return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> tickets) {
    t=tickets;
    sort(t.begin(), t.end(), cmp);
		v.push_back("ICN");
    dfs("ICN", 0);
    return answer;
}
