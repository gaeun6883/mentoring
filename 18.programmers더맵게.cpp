//mentoring 18. 2021.11.21
//que의 사용

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
   priority_queue<int,vector<int>,greater<int> > Q;
    for(int n:scoville)
        Q.push(n);
    while(Q.top()<K){
        int a, b, result;
        a=Q.top();
        Q.pop();
        b=Q.top();
        Q.pop();
        result=a+(b*2);
        Q.push(result);
        ++answer;
        if(Q.size()<2)
            break;
    }
    if(Q.top()<K)
        answer=-1;
    return answer;
}
