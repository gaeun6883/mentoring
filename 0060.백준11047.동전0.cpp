//mentoring 60. 2022.1.11
//그리디(greedy)

#include <iostream>
using namespace std;

int main() {
	int n, k, a[15];
	int ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = n - 1; i >= 0; i--) {
		ans += k / a[i];
		k %= a[i];
	}
	cout << ans;
}
