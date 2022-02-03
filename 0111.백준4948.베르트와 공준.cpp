//mentoring 111. 2022.2.2
//소수

#include <iostream>
using namespace std;

bool prime(int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++)
			if (prime(i))
				cnt++;
		cout << cnt<<"\n";
	}
	return 0;
}
