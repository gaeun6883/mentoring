//mentoring 122. 2022.2.8

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str, bomb, result = "";
	cin >> str;
	cin >> bomb;

	vector<char> s;
	for (int i = 0; i < str.length(); i++) {
		s.push_back(str[i]);
		if (str[i] == bomb.back() && s.size() >= bomb.size()) {
			bool state = true;
			for (int j = 0; j < bomb.size(); j++) {
				if (bomb[j] != s[s.size() - bomb.size() + j]) {
					state = false;
					break;
				}
			}
			if (state == true) {
				for (int j = 0; j < bomb.length(); j++)
					s.pop_back();
			}
		}
	}

	if (s.empty())
		cout << "FRULA";
	else {
		for (auto c : s) {
			cout << c;
		}
	}
	return 0;
}

//초기코드: 시간초과
/*int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str, bomb, result="";
	cin >> str;
	cin >> bomb;

	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
		if (str[i] == bomb.back() && s.size() >= bomb.size()) {
			string tmp="";
			for (int j = 0; j < bomb.size(); j++) {
				tmp = s.top()+tmp;
				s.pop();
			}
			if (bomb != tmp) {
				for (int j=0; j<tmp.length(); j++)
					s.push(tmp[j]);
			}
		}
	}

	if (s.empty())
		cout << "FRULA";
	else {
		while (!s.empty()) {
			result = s.top() + result;
			s.pop();
		}
		cout << result;
	}
	return 0;
}*/
