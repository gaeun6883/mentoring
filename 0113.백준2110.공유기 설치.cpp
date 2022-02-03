//mentoring 113. 2022.2.3
//이분탐색

#include <iostream>
#include <algorithm>
#define MAX 200003
using namespace std;

int n, c;
int arr[MAX];

int binary_search() {
	int left = 1, right = arr[n - 1];
	int result = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1, tmp = 0;
		for (int i = 1; i < n; i++)
			if (arr[i] - arr[tmp] >= mid) {
				tmp = i;
				cnt++;
			}

		if (cnt >= c) {
			left = mid + 1;
			result = mid;
		}
		else right = mid - 1;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	cout << binary_search();
	return 0;
}
