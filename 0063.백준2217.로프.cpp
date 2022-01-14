//mentoring 63. 2022.1.12
//그리디

#include <iostream>
#include <algorithm>
#define MAX 1000003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[MAX];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum = max(sum, arr[n - i] * i);
	cout << sum;
}
