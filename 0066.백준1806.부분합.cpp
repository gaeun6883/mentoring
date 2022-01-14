//mentoring 66. 2022.1.14
//투 포인터

#include <iostream>
#include <algorithm>
#define MAX 100003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n >> s;
	int arr[MAX];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int result=n+1, sum = arr[0], l = 0, r = 0;
	while (l <= r && r < n) {
		if (sum < s)
			sum += arr[++r];
		else {
			result = min(result, r - l + 1);
			sum -= arr[l++];
		}
	}

	if (result == n + 1)
		result = 0;
	cout << result;
	return 0;
}
