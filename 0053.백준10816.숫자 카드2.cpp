//mentoring 53.2022.1.7
//이진탐색 응용

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> list;

int minIdx(int target) {
    int left = 0, right = list.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (list[middle] >= target) {
        }
        else left = middle + 1;
    }
    return left;
}

int maxIdx(int target) {
    int left = 0, right = list.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (list[middle] <= target) {
            left = middle + 1;
        }
        else right = middle - 1;
    }
    return right;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;
    int n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        list.push_back(n);
    }
    sort(list.begin(), list.end());
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> n;
        int ans = maxIdx(n) - minIdx(n) + 1;
        cout << ans << " ";
    }
    return 0;
}
