//mentoring 268. 2022.7.15
//priority_queue

#include <iostream>
#include <queue>
#define MAX 103
using namespace std;

int arr[MAX];
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, n;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		q.push(arr[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		int a = q.top();
		for (int j = 0; j < k; j++) {
			int b = a * arr[j];
			if (b < pow(2, 31))
				q.push(b);
		}
		while (q.top() == a)
			q.pop();
	}
	cout << q.top();
	return 0;
}
