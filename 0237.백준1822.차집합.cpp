//mentoring 237. 2022.5.20
//set

#include <iostream>
#include <set>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    set<int> s;
    for (int i = 0; i < a; i++){
        int n;
        cin >> n;
        s.insert(n);
    }

    for (int i = 0; i < b; i++){
        int n;
        cin >> n;
        auto num = s.find(n);
        if (num == s.end()) continue;
        else s.erase(num);
    }
    cout << s.size() << "\n";
    for (int n : s)
        cout << n << " ";
    return 0;
}
