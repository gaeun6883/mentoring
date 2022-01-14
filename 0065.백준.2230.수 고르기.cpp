//mentoring 65. 2022.1.13
//투 포인터

#include <iostream>
#include <algorithm>
#define MAX 1000005
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A[MAX];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	sort(A, A + n);

	int en = 0, minN=0X7fffffff;
	for (int i = 0; i < n; i++) {
		while (en < n && A[en] - A[i] < m)
			en++;
		if (en == n) break;
		minN = min(minN, A[en] - A[i]);
	}
	cout << minN;
}
