//mentoring 19. 2021.11.23
//que의 사용

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer={0,0};
    deque<int> Q;
    for(int i=0; i<operations.size(); i++){
        int n=stoi(operations[i].substr(2));
        if(operations[i][0]=='I'){
            Q.push_back(n);
            sort(Q.begin(), Q.end());
        }
        else if(!Q.empty()){
            if(n==1)
                Q.pop_back();
            if(n==-1)
                Q.pop_front();
        }
    }
    if(!Q.empty()){
        answer.clear();
        answer.push_back(Q.back());
        answer.push_back(Q.front());
    }
    return answer;
}
