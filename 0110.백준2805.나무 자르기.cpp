//mentoring 110. 2022.2.2
//이분탐색

#include <iostream>
#include <algorithm>
#define MAX 1000003
using namespace std;

int n, m;
int arr[MAX];

int binary_search() {
	long long result = 0;
	long long left = 0, right = arr[n - 1];
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++)
			if (arr[i] - mid > 0)
				cnt += (arr[i] - mid);
		if (cnt >= m) {
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

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	cout << binary_search();
	return 0;
}
