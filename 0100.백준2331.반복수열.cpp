//mentoring 100. 2022.1.28
//수열

#include <iostream>
#include <cmath>
using namespace std;

int check[300000];
int a, p;

int next(int n) {
	int num = 0;
	while (n != 0) {
		num += pow(n % 10, p);
		n /= 10;
	}
	return num;
}

int main() {
	cin >> a >> p;
	check[a]++;

	int n = next(a);

	int cnt = 1;
	while (check[n] == 0) {
		cnt++;
		check[n] = cnt;
		n = next(n);
	}
	cout << check[n] - 1;
}
