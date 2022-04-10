//mentoirng 210. 2022.4.5
//구현 

#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	string n="";
	int num = 0, result = 0;
	bool state = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-' || s[i] == '+') {
			if (state) result -= num;
			else result += num;
			num = 0;
			if (s[i] == '-') state = true;
		}
		else {
			n += s[i];
			if (!isdigit(s[i + 1])) {
				num = stoi(n);
				n = "";
			}
		}
	}
	if (state) result -= num;
	else result += num;
	cout << result;
	return 0;
}
