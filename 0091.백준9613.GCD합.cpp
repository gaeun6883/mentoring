//mentoring 91. 2022.1.25
//유클리드 호제법

#include <iostream>
#define MAX 103
using namespace std;

int solution(int a, int b) {
	if (b == 0)
		return a;
	return solution(b, a % b);
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		int arr[MAX];
		for (int n = 0; n < N; n++)
			cin >> arr[n];

		long long sum = 0;
		for (int i = 0; i < N; i++)
			for (int j = i; j < N; j++) {
				if (i == j) continue;
				sum += solution(arr[i], arr[j]);
			}
		cout << sum << "\n";
	}
	return 0;
}
