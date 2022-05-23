//mentoring 234. 2022.5.17
//동적계획법

#include <string>
#include <vector>
#include <climits>
using namespace std;
int answer=INT_MAX, n, num;

void dfs(int idx, int cnt){
    if (cnt > 8) return;
    if (idx == num) {
        answer = min(answer, cnt);
        return;
    }
    int tmp= 0;
    for (int i = 1; i < 9 ; i++) {
        tmp = tmp * 10 + n;
        dfs(idx+tmp,cnt+i);
        dfs(idx-tmp,cnt+i);
        dfs(idx*tmp,cnt+i);
        dfs(idx/tmp,cnt+i);
    }
}
int solution(int N, int number) {
    n=N;
    num=number;
    dfs(0,0);
    if (answer == INT_MAX) return -1;
    return answer;
}
