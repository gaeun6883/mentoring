//mentoring 115. 2022.2.4
//비트마스크

#include <iostream>
#include <algorithm>
#define MAX 22
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s[MAX];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n);

	int result = 1;
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j))
				sum += s[j];

		if (result < sum) break;
		else if (result == sum)
			result = sum + 1;
	}

	cout << result;
	return 0;
}
