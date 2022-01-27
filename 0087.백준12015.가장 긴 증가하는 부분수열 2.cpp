//mentoring 87. 2022.1.24
//다이나믹 알고리즘: LIS알고리즘 + 이분탐색 알고리즘(lower_bound: mentoring 53, 54)

#include <iostream>
#include <vector>
#define MAX 100004
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
    cin >> n;
    vector<int> v;
    int arr[MAX];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    v.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        auto iter = lower_bound(v.begin(), v.end(), arr[i]);
        if (iter == v.end())
            v.push_back(arr[i]);
        else
            *iter = arr[i];
    }
    cout << v.size();
    return 0;
}

//LIS 알고리즘만으로 푼 초기 코드: MAX가 10만이 넘을 시 제대로 작동하지 않는다.
/*int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[MAX], dp[MAX] = { 1 };
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        result = max(result, dp[i]);
    }
    cout << result;
}*/
