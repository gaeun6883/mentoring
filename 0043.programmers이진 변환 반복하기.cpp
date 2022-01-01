//mentoring 43. 2021.1.2
//이진수-n진수 게임 응용

#include <string>
#include <vector>
using namespace std;

int cnt_0=0;
string change(string s){
    int cnt_1=0;
    for(int i=0; i<s.length(); i++)
        if(s[i]=='1') cnt_1++;
        else cnt_0++;

    string binary="";
    while (cnt_1 > 0){//2진수 변환
        binary= to_string(cnt_1 % 2)+binary;
        cnt_1 = cnt_1 / 2;
    }
    return binary;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt=0;
    while(s!="1"){
        s=change(s);
        cnt++;
    }
    answer.push_back(cnt);
    answer.push_back(cnt_0);
    return answer;
}
