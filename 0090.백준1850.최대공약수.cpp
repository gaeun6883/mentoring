//mentoring 90. 2022.1.25
//최소공배수: 유클리드 호제법

#include <iostream>
using namespace std;

int solution(long long a, long long b) {
	if (a % b == 0)
		return b;
	return solution(b, a % b);
}

int main() {
	long long a, b;
	cin >> a >> b;
	long long n = solution(a, b);
	while (n--)
		cout << "1";
	return 0;
}
