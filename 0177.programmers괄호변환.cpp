//mentoring 177. 2022.3.8
//재귀함수

#include <string>
#include <stack>
using namespace std;

bool check(string s){
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(st.empty()&&s[i]==')')
            return false;
        if(s[i]=='(')
            st.push(s[i]);
        else st.pop();
    }
    if(st.empty())
        return true;
    else return false;
}

string solution(string p) {
    if(p.empty()) return p; // step 1
    string answer = "";

    string u = "", v = "";//stpe 2
    int cnt0 = 0, cnt1 = 0;
    for(int i=0; i<p.length(); ++i) {
        if(p[i] == '(') cnt0++;
        else cnt1++;
        if(cnt0 == cnt1) {
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }

    if(check(u)) answer = u + solution(v); // step 3
    else { //step 4
        answer = "(" + solution(v) + ")";
        for(int i=1; i<u.length()-1; i++)
            answer += u[i] == '(' ? ')' : '(';
    }

    return answer;
}
