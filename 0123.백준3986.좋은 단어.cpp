//mentoring 123. 2022.2.9
//스택

#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int cnt = 0;
	while (n--) {
		string str;
		cin >> str;

		stack<char> s;
		for (int i = 0; i < str.length(); i++)
			if (s.empty() || s.top() != str[i])
				s.push(str[i]);
			else s.pop();

		if (s.empty())
			cnt++;
	}
	cout << cnt++;
	return 0;
}
