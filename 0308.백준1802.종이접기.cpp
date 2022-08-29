//mentoring 308. 2022.8.25
//binary search

#include <iostream>
using namespace std;

bool sol(string s) {
	if (s.length() % 2 == 0) return false;
	int l = 0, r = s.length() - 1;
	while (r > l) {
		int mid = (r + l) / 2;
		for (int i = l, j = r; i < mid; i++, j--)
			if (s[i] == s[j]) return false;
		r = mid - 1;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (sol(s)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
