//mentoring 62. 2022.1.12
//그리디

#include <iostream>
#include <algorithm>
#define MAX 1000003
using namespace std;

//보물
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int A[MAX], B[MAX];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	sort(A, A + N);
	sort(B, B + N);
	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += A[i] * B[N - 1 - i];
	cout << sum;
}
