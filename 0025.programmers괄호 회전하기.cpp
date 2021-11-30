//mentoring 25. 2021.11.30
//stack 응용

#include <string>
#include <vector>
#include <stack>
using namespace std;

bool right_ps(string s){
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            st.push(s[i]);
        if(s[i]==')'){
            if(st.empty()||st.top()!='(')
                return false;
            else
                st.pop();
        }
        if(s[i]==']'){
            if(st.empty()||st.top()!='[')
                return false;
            else
                st.pop();
        }
        if(s[i]=='}'){
            if(st.empty()||st.top()!='{')
                return false;
            else
                st.pop();
        }
    }
    if(!st.empty())
        return false;
    else return true;
}
int solution(string s) {
    int answer = 0;
    string S=s;
    for(int i=0; i<s.length(); i++){
        string first=S.substr(0,1);
        string remain=S.substr(1);
        string spinS=remain+first;
        if(right_ps(spinS))
            ++answer;
        S=spinS;
    }
    return answer;
}
