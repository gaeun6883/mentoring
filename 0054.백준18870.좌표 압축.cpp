//mentoring 54. 2022.1.8
//이진탐색 응용

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000003

int x[MAX];
vector<int> tmp, uni;

int minIdx(int target) {
	int left = 0, right = uni.size() - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (uni[middle] >= target) {
			right = middle - 1;
		}
		else left = middle + 1;
	}
	return left;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		tmp.push_back(x[i]);
	}
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < n; i++)
		if (i == 0 || tmp[i - 1] != tmp[i])
			uni.push_back(tmp[i]);

	for (int i = 0; i < n; i++)
		cout << minIdx(x[i]) << ' ';
}
