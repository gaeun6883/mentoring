//mentoring 267. 2022.7.14
//priority_queue

#include<iostream>
#include<queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;

    while (n--) {
        int num;
        cin >> num;
        if (q1.size() == q2.size())
            q1.push(num);
        else q2.push(num);

        if (!q1.empty() && !q2.empty() && q1.top() > q2.top()) {
            int a = q1.top();
            int b = q2.top();
            q1.pop();
            q2.pop();
            q1.push(b);
            q2.push(a);
        }
        cout << q1.top() << '\n';
    }
    return 0;
}
