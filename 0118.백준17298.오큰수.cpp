//mentoring 118. 2022.2.6
//stack

#include <iostream>
#include <stack>
#define MAX 1000003
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, arr[MAX];
	cin >> n;
	stack<int> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int answer[MAX];
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= arr[i])
			s.pop();

		if (s.empty())
			answer[i] = -1;
		else answer[i] = s.top();

		s.push(arr[i]);
	}

	for (int i = 0; i < n; i++)
		cout << answer[i] << " ";
	return 0;
}
