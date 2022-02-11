//mentoring 121. 2022.2.8
//스택. 후위표기식

#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str, result="";
	cin >> str;

	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
        //괄호
        if (str[i] == '(')
            s.push(str[i]);
        else if (str[i] == ')') {
            while (s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.pop();
        }
        //사칙연산
        else if (str[i] == '+' || str[i] == '-') {
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else if (str[i] == '*' || str[i] == '/') {
            while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
                result += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        //문자
        else
            result += str[i];
    }
    while (!s.empty()) {
        result += s.top();
        s.pop();
	}

	cout << result;
	return 0;
}
