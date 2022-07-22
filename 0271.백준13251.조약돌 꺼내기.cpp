//mentoring 271. 2022.7.18
//구현

#include <iostream>
#define MAX 55
using namespace std;

int n, m, k, arr[MAX], sum = 0;
double result = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	cin >> k;

	for (int i = 1; i <= m; i++) {
		if (arr[i] < k) continue;
		double tmp = 1.0;
		for (int j = 0; j < k; j++)
			tmp *= (double)(arr[i] - j) / (sum - j);
		result += tmp;
	}
	cout << fixed;
	cout.precision(15);
	cout << result;

	return 0;
}
