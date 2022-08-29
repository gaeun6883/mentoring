//mentoring 311. 2022.8.28
//dynamic programming

#include <iostream>
using namespace std;

int n, dpMax[2][3] = { 0, }, dpMin[2][3] = { 0, };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        dpMax[1][0] = max(dpMax[0][0], dpMax[0][1]) + a;
        dpMax[1][1] = max(dpMax[0][0], max(dpMax[0][1], dpMax[0][2])) + b;
        dpMax[1][2] = max(dpMax[0][1], dpMax[0][2]) + c;

        dpMin[1][0] = min(dpMin[0][0], dpMin[0][1]) + a;
        dpMin[1][1] = min(dpMin[0][0], min(dpMin[0][1], dpMin[0][2])) + b;
        dpMin[1][2] = min(dpMin[0][1], dpMin[0][2]) + c;

        for (int i = 0; i < 3; i++) {
            dpMax[0][i] = dpMax[1][i];
            dpMin[0][i] = dpMin[1][i];
        }
    }

    int resultMax= max(dpMax[0][0], max(dpMax[0][1], dpMax[0][2]));
    int resultMin = min(dpMin[0][0], min(dpMin[0][1], dpMin[0][2]));
    cout << resultMax << " " << resultMin;
    return 0;
}
