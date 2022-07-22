//mentoring 269. 2022.7.16
//유클리드의 호제법(gcd)

#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0)return b;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, d;
	cin >> a >> b;
	cin>>c >> d;

	int A = a * d + c * b;
	int B = d * b;
	int n = gcd(A, B);

	cout << A / n <<" "<< B / n;
	return 0;
}
