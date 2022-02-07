//mentoring 120. 2022.2.7
//stack

#include <iostream>
#include <stack>
#include <string>
#define MAX 30
using namespace std;

stack<double> s;
void calc(char op, double x, double y);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, alpha_to_num[MAX] = { 0, };
	string str;
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++)
		cin >> alpha_to_num[i];

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			s.push(alpha_to_num[str[i] - 'A']);
		else {
			double a, b;
			b = s.top();
			s.pop();
			a = s.top();
			s.pop();

			calc(str[i], a, b);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top();
	return 0;
}

void calc(char op, double x, double y) {
	if (op == '+')
		s.push(x + y);

	if (op == '-')
		s.push(x - y);

	if (op == '*')
		s.push(x * y);

	if (op == '/')
		s.push(x / y);
	return;
}
