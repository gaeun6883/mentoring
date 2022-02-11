//mentoring 124. 2022.2.9
//우선순위 큐

#include <iostream>
#include <queue>
#define MAX 1000003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	priority_queue<int, vector<int>, greater<int> > Q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		Q.push(num);
	}

	int sum = 0;
	while (Q.size()>1) {
		int a, b;
		a = Q.top();
		Q.pop();
		b = Q.top();
		Q.pop();

		Q.push(a + b);
		sum += a + b;
	}

	cout << sum;
	return 0;
}
