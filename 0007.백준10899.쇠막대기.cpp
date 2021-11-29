//mentoring 7. 2021.11.9
//stack의 응용

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	string s;
	cin >> s;
	int count=0;
	stack<char> st;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			if (s[i + 1] == ')')
				count += st.size();
			else
				st.push(s[i]);
		}
		else {
			count++;
			st.pop();
		}

	}
	count += st.size();
	cout << count;

	return 0;
}

//다른 코드
/*for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else {
			if (s[i - 1] == '(') {
				st.pop();
				count += st.size();
				//i++; //왜 더하기?
			}
			else {
				count++;
				st.pop();
			}

		}

	}*/
