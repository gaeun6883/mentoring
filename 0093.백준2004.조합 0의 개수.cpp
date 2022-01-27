//mentoring 93. 2022.1.26

#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n>> m;

	long long cnt_2 = 0, cnt_5 = 0;
	for (long long i = 2; i <= n; i *= 2)
		cnt_2 += n / i;
	for (long long i = 2; i <= m; i *= 2)
		cnt_2 -= m / i;
	for (long long i = 2; i <= (n-m); i *= 2)
		cnt_2 -= (n - m) / i;

	for (long long i = 5; i <= n; i *= 5)
		cnt_5 += n / i;
	for (long long i = 5; i <= m; i *= 5)
		cnt_5 -= m / i;
	for (long long i = 5; i <= (n - m); i *= 5)
		cnt_5 -= (n - m) / i;

	cout << min(cnt_2, cnt_5);
	return 0;
}
