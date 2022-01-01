//mentoring 41. 2022.1.1
//반복문 while의 응용

#include <string>
#include <vector>
using namespace std;

string changeNumber(int n,int num){
    string result = "";
    int div=num, mod;
    char c;
    while(div > 0){
        mod=div%n;
        if(mod>=10) c=(mod-10)+'A';
        else c=mod+'0';
        result=c+result;
        div=div/n;
    }
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string change="0";
    for(int i=1; change.size()<t*m; i++)//change.size()<t*m
        change+=changeNumber(n, i);

    for(int i=p-1; answer.size()<t; i+=m)
        answer+=change[i];
    return answer;
}
