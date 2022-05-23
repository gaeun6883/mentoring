//mentoring 238. 2022.5.21
//이진탐색

#include <iostream>
#define MAX 1000003
using namespace std;

int n, m, arr[MAX],result;

int sol() {
    int r = 2000000000;
    int l = 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += arr[i] / mid;
        if (cnt >= m) {
            l = mid + 1;
            result = mid;
        }
        else
            r = mid - 1;
    }
    return result;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cout << sol();
	return 0;
}
