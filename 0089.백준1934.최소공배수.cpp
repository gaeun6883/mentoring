//mentoring 89. 2022.1.25

#include <iostream>
using namespace std;

int solution(int a, int b) {
	int Max = max(a, b);
	int Min = min(a, b);
	for (int i = Max;; i += Max)
		if (i % Min == 0)
			return i;
}

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++) {
		int a, b;
		cin >> a >> b;
		cout << solution(a, b)<<"\n";
	}
	return 0;
}
