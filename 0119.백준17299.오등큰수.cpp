//mentoring 2022.2.7
//stack-백준17298.오큰수와 동일

#include <iostream>
#include <stack>
#define MAX 1000003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a[MAX], cnt[MAX] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a[i]=num;
		cnt[num]++;
	}

	int answer[MAX] = { 0, };
	stack<int> s;
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && cnt[s.top()] <= cnt[a[i]])
			s.pop();

		if (s.empty() || i == n)
			answer[i] = -1;
		else if (cnt[s.top()] > cnt[a[i]])
			answer[i] = s.top();
		s.push(a[i]);
	}

	for (int i = 0; i < n; i++)
		cout << answer[i] << " ";
	return 0;
}
