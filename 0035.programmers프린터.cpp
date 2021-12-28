//mentoring 35. 2021.12.28
//큐와 우선순위

#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;//<우선순위, 위치>
    priority_queue<int> sortPrior;
    for(int i=0; i<priorities.size(); i++){
        q.push({priorities[i],i});
        sortPrior.push(priorities[i]);
    }

    while(true){
        int prior=q.front().first;
        int idx=q.front().second;
        q.pop();
        if(prior==sortPrior.top()){
            sortPrior.pop();
            answer++;
            if(idx==location)
                break;
        }
        else q.push({prior, idx});
    }

    return answer;
}
