//mentroing 214. 2022.4.9
//구현

#include <iostream>
#define MAX 10003
using namespace std;

int n, m, a[MAX], cnt = 0,sum=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			if (sum == m) {
				cnt++;
				break;
			}
			else if (sum > m) break;

		}
	}

	cout << cnt;
	return 0;
}
