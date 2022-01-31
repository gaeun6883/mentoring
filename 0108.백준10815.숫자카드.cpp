//mentoring 108. 2022.2.1
//이분탐색

#include <iostream>
#include <algorithm>
#define MAX 500003
using namespace std;

int n;
int card[MAX];

int search(int num) {
	int left = 0, right = n-1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (card[mid] == num)
			return 1;

		if (card[mid] > num)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> card[i];
	sort(card, card + n);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		cout << search(num) << " ";
	}
	return 0;
}
