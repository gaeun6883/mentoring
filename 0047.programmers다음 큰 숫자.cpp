//mentoring 47. 2022.1.6
//2진수 만들기-n진수 생성 변형

#include <string>
#include <vector>

using namespace std;

int cnt_binary1(int num){
    int cnt=0;
    while(num>0){
        if((num%2)==1)
            ++cnt;
        num/=2;
    }
    return cnt;
}
int solution(int n) {
    int answer = 0;
    int num=cnt_binary1(n);
    for(int i=n+1; i<1000002;i++)
        if(num==cnt_binary1(i)){
            answer=i;
            break;
        }
    return answer;
}
