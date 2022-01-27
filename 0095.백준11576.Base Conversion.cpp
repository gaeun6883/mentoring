//mentoring 95. 2022.1.26
//스택

#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int m;
	cin >> m;

	int num=0;
	for (int i = 1; i <= m; i++) {
		int n;
		cin >> n;
		num += n * pow(A, m - i);
	}

	stack<int> s;
	while (num) {
		s.push(num % B);
		num /= B;
	}

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
