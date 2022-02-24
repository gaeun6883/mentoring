//mentoring 155. 2022.2.24
//다이나믹 프로그래밍

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	if (n % 2 == 0)
		cout << "CY";
	else
		cout << "SK";
	return 0;
}
