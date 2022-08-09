//mentoring 283. 2022.7.31
//이분탐색

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 40004
using namespace std;

int n, a[MAX], b[MAX], c[MAX], d[MAX];
long long result = 0;
vector<int> v1;//a+b
vector<int> v2;//c+d

void sol();
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			v1.push_back(a[i] + b[j]);
			v2.push_back(c[i] + d[j]);
		}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	sol();
	cout << result;
	return 0;
}

void sol() {
	long long l = 0, r = n * n - 1;
	while (l < n * n && r >= 0) {
		int sum = v1[l] + v2[r];
		if (sum == 0) {
			int i=1, j = 1;
			while (l + i < n * n && v1[l] == v1[l + i]) i++;
			while (r - j >= 0 && v2[r] == v2[r - j]) j++;
			result += (long long)i * j;
			l += i;
			r -= j;
		}
		else if (sum > 0) r--;
		else l++;
	}
}
