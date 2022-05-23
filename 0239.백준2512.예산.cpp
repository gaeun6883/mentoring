//mentoring 239. 2022.5.22
//이진탐색

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10003
using namespace std;

int n, m, maxM = 0;
vector<int> arr;

int sol() {
    int result=0;
    if (m > maxM) result = arr.back();
    else{
        int l = 0;
        int r = arr[n - 1];

        while (l <= r) {
            int mid = (l + r) / 2;
            int idx = lower_bound(arr.begin(), arr.end(), mid) - arr.begin();

            int sum = 0;
            for (int i = 0; i < idx; i++)
                sum += arr[i];
            sum += (mid * (n - idx));

            if (sum > m)
                r = mid - 1;
            else {
                l = mid + 1;
                result = mid;
            }
        }
    }
    return result;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
    arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxM += arr[i];
	}
	cin >> m;
	sort(arr.begin(), arr.end());

	cout << sol();
	return 0;
}
