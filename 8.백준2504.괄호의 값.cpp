//mentoring 8. 2021.11.10
//stack 심화문제, 분배법칙
//다시 풀기
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<char> st;
	string s;
	cin >> s;
	bool flag=true;
	int result=0,temp=1, sum=0;

	for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				st.push(s[i]);
				temp *= 2;
			}
			else if (s[i] == '[') {
				st.push(s[i]);
				temp *= 3;
			}

			else if (s[i] == ')') {
				if (st.empty() || st.top() != '(') {
					flag = false;
					break;
				}
				if (s[i - 1] == '('){
					result += temp;
				st.pop();
				temp /= 2;
			}
			else if(st.top()=='('){
				st.pop();
				temp /= 2;
			}
			}
			else {
				if (st.empty() || st.top() != '[') {
					flag = false;
					break;
				}
				if (s[i - 1] == '['){
					result += temp;
				st.pop();
				temp /= 3;
			}
			else if(st.top()=='('){
				st.pop();
				temp /= 3;
			}
			}
		}

		if (!flag || !st.empty())
			cout << "0";
		else
			cout << result;
}

//초기코드
/*int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> st;
	sing s;
	cin >> s;
	int result=1,tmp=0, sum=0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '[')
			st.push(s[i]);
		else if (s[i] == ')') {
			if (st.empty() || st.top() == '[') {
				sum = 0;
				break;
			}
			result *= 2;
			if (st.top() != '(') {
				result *= st.top();
				st.pop();
			}
			st.pop();
		}
		else if (s[i] == ']') {
			if (st.empty() || st.top() == '(') {
				sum = 0;
				break;
			}
			result *= 3;
			if (st.top() != '[') {
				result *= tmp;
				st.pop();
			}
			st.pop();
		}
		else {
			tmp = s[i] - '0';
			st.push(tmp);
		}

		if ((s[i]==')'||s[i]==']')&&(s[i + 1] == '(' || s[i + 1] == '[')) {
			sum += result;
			result = 1;
		}
	}
	if (!st.empty())
		sum = 0;
	cout << sum;
}*/
