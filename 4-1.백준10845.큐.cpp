//mentoring 4. 2021.11.5
//stl 큐의 사용

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string order;
        cin >> order;
        if (order == "push") {
            int n;
            cin >> n;
            q.push(n);
        }
        else if (order == "pop") {
            if (q.empty()) cout << -1 << endl;
            else {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (order == "size") {
            cout << q.size() << endl;
        }
        else if (order == "empty") {
            if (q.empty())
                cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if (order == "front") {
            if (q.empty())
                cout << -1 << endl;
            else
                cout << q.front() << endl;
        }
        else if (order == "back") {
            if (q.empty())
                cout << -1 << endl;
            else
                cout << q.back() << endl;
        }
    }
    return 0;
}
