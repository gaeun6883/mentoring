//mentoring 242. 2022.5.25
//두포인터 

#include <iostream>
#include <climits>
#define MAX 100003
using namespace std;

int n, arr[MAX], result[2];

void sol() {
    int l = 0, r = n - 1;
    int a,b,x = INT_MAX;

    while (l < r) {
        int sum = arr[l] + arr[r];

        if (abs(x) > abs(sum)) {
            x = sum;
            a = arr[l];
            b = arr[r];
        }

        if (sum == 0) break;
        else if (sum > 0) r--;
        else l++;
    }
    result[0] = a;
    result[1] = b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sol();
    cout << result[0] << " " << result[1];
    return 0;
}
