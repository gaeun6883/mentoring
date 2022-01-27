//mentoring 96. 2022.1.26
//소수의 덧셈

#include <iostream>
#include <cmath>
using namespace std;

bool prime(int n){
	for (int i = 2; i <= sqrt(n); i++){
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) return 0;
		bool flag = false;
		int i;
		for ( i = 3; i <= n / 2; i += 2)
			if (prime(i) && prime(n - i)) {
				flag = true;
				break;
			}
		if (flag)
			cout << n << " = " << i << " + " << n-i << '\n';
		else
			cout << "Goldbach's conjecture is wrong\n";
	}
}
