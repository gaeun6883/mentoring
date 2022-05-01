//mentoring 217. 2022.4.29
//구현

#include <iostream>
#define MAX 203
using namespace std;

int n, k, a[MAX], belt[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= 2 * n; i++)
		cin >> a[i];

	int in = 1, out = n, cnt = 0, result = 0;
	while (cnt < k) {//step 4
		result++;

		if (in - 1 > 0) in--;//step 1
		else in = 2 * n;
		if (out - 1 > 0) out--;
		else out = 2 * n;

		if (belt[out] == 1) belt[out] = 0;

		for (int i = out - 1; i > out - n; i--){//step 2
			int robot = i;
			int tmp = 0;
			if (i < 1) robot = 2 * n + i;

			tmp = robot + 1;
			if (tmp > 2 * n) tmp -= 2 * n;

			if (belt[robot] == 1 && a[tmp] != 0 && belt[tmp] == 0){
				belt[robot] = 0;
				belt[tmp] = 1;
				a[tmp]--;//step 2-1
				if (a[tmp] == 0) cnt++;
			}
			if (belt[out] == 1) belt[out] = 0;
		}

		if (a[in] > 0) {//step 3
			belt[in]++;
			a[in]--;
			if (a[in] == 0) cnt++;
		}
	}
	cout << result;
	return 0;
}
