//mentoring 157. 2022.2.25
//다이나믹 프로그래밍

#include <iostream>
#define MAX 1003
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, dp[MAX] = { 0,1,0,1,1 };
    cin >> n;
    for (int i = 5; i <= n; i++)
        if (dp[i - 1] + dp[i - 3] + dp[i - 4] < 3)
            dp[i] = 1;
        else dp[i] = 0;

    if (dp[n] == 1)
        cout << "SK";
    else
        cout << "CY";
    return 0;
}
