//mentoring 57. 2022.1.9
//큐의 응용

#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> D;

    for(int i=0; i<progresses.size(); i++){
        int n=(100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i]!=0)
            n+=1;
        D.push(n);
    }

    int day=1;
    while(!D.empty()){
        int cnt=0;
        while(!D.empty()&&D.front()<=day){
            D.pop();
            cnt++;
        }
        if(cnt>0)
            answer.push_back(cnt);
        day++;
    }
    return answer;
}
