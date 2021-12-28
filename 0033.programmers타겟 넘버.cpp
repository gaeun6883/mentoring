//mentoring 33. 2021.12.27
//dfs응용

#include <string>
#include <vector>
using namespace std;

int cnt=0;
void dfs(int cur, vector<int> numbers, int sum, int target){
    if(cur==numbers.size()){
        if(sum==target)
            cnt++;
        return;
    }
    dfs(cur+1, numbers,sum+numbers[cur],target);
    dfs(cur+1, numbers,sum-numbers[cur],target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(0, numbers,0,target);
    answer=cnt;
    return answer;
}
