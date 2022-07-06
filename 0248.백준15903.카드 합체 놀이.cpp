//mentoring 248. 2022.6.22
//구현 

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1003
using namespace std;

int n, m;
vector<long long> a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}

	long long result=0;
	for (int i = 0; i < m; i++) {
		long long tmp;
		sort(a.begin(), a.end());
		tmp = a[0] + a[1];
		a[0] = a[1] = tmp;
	}

	for (int i = 0; i < a.size(); i++)
		result += a[i];
	cout << result;
	return 0;
}
