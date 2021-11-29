//mentoring 5. 2021.11.6
//mentoring 1.의 괄호 응용, stack

#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define FALSE 0
#define TRUE 1

//초기코드
/*int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<char> circle;
	stack<char> rect;

	while (true) {
		char s[100] = { 0, };
		cin.getline(s, 100, '.');

		if (s[0] == '.')//��������
			break;

		int result = TRUE;

		for (int i = 0; i < 100; i++) {
			if (s[i] == '(')
				circle.push(s[i]);
			else if (s[i] == ')') {
				if (circle.empty()) {
					cout << "no1\n";
					result = FALSE;
					break;
				}
				circle.pop();
			}

			if (s[i] == '[')
				rect.push(s[i]);
			else if (s[i] == ']') {
				if (rect.empty()) {
					cout << "no2\n";
					result = FALSE;
					break;
				}
				rect.pop();
			}
		}

		if (result == FALSE)
			continue;
		else if (circle.empty() && rect.empty())
			cout << "yes\n";
		else
			cout << "no3\n";
	}
}*/
//getline에 대한 이해 부족

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);



	while (true) {
		char s[101] = { 0, };//string s;

		//getline에서 마지막 매개변수값으로 제한자 '.'을 넣은 경우, "."이 왔을때 바로 null문자가 오므로 loop문 탈출이 불가능(바로 아래 if (s[0] == '.')이 무용지물됨)
		cin.getline(s, 101);//getline(cin,s);
		if (s[0] == '.') {
			break;
		}

		int result = TRUE;

		// 1. circle과 rect는 매 loop마다 초기화가 되어야하는 값이므로 while문 안에 넣음
		// 2. circle과 rect을 따로 구분한다면 만약 번갈아나오는 상황의 경우에도 yes로 나올 수 있음  "([)]"
		// 3. 따라서 하나의 stack만을 사용해서 확인해야 한다.
		stack<char> stk;

		for (int i = 0; i < 100; i++) {
			if (s[i] == '('||s[i]=='[')
				stk.push(s[i]);
			else if (s[i] == ')') {
				if (stk.empty()||stk.top()=='[') {
					cout << "no\n";
					result = FALSE;
					break;
				}
				stk.pop();
			}
			else if (s[i] == ']') {
				if (stk.empty()||stk.top()=='(') {
					cout << "no\n";
					result = FALSE;
					break;
				}
				stk.pop();
			}
		}

		if (result == FALSE)
			continue;
		else if (stk.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}
}
