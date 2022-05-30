//mentoring 245. 2022.5.28
//구현

#include <iostream>
#include <algorithm>
#define MAX 20003
using namespace std; int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int a[MAX], b[MAX];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < m; i++)
			cin >> b[i];
		sort(a, a + n);
		sort(b, b + m);

		int start = 0, sum = 0, x = 0;
		for(int i = 0; i < n; i++){
			int cur = start;
			while(cur < m && a[i] > b[cur])
				cur++;
			x += (cur - start);
			sum += x;
			start = cur;
		}
		cout << sum << "\n";
	}
}
