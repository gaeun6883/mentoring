//mentoring 109. 2022.2.1
//이분탐색

#include <iostream>
#include <algorithm>
#define MAX 10003
using namespace std;

int k, n;
int line[MAX];

int binary_search() {
	long long result = 0;
	long long left = 1, right = line[k-1];
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0; i < k; i++)
			cnt += line[i] / mid;
		if (cnt >= n) {
			left = mid + 1;
			result = max(result, mid);
		}
		else right = mid - 1;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> line[i];
	sort(line, line + k);

	cout << binary_search();
	return 0;
}
