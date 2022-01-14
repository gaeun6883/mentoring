//mentoring 61. 2022.1.11
//그리디

#include <iostream>
#include <utility>
#include <algorithm>
#define MAX 100005
using namespace std;

int main() {
	int n;
	pair<int, int> s[MAX];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i].second >> s[i].first;
	sort(s, s + n);
	int ans = 0, t = 0;
	for (int i = 0; i < n; i++) {
		if (t > s[i].second) continue;
		ans++;
		t = s[i].first;
	}
	cout << ans;
}
