//mentoring 1. 2021.10.29
//stl의 stack 사용

#include <iostream>
#include <string>
#include <stack>
#define MAX 51
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> s;
		int outLoop_break = 0;

		stack<char>stack;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(')
				stack.push(s[i]);
			else if (s[i] == ')') {
				if (stack.empty()) {
					cout << ("NO\n");
					outLoop_break = 1;
					break;
				}
				stack.pop();
			}
		}

		if (outLoop_break == 1)
			continue;
		else if (stack.empty())
			cout << ("YES\n");
		else
			cout << ("NO\n");

	}

	return 0;
}
