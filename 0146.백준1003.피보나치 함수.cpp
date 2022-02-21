//mentoring 146. 2022.2.20
//다이나믹 프로그래밍

#include <iostream>
#define MAX 42
using namespace std;

int main(){
    int t, zero[MAX] = { 1 }, one[MAX] = { 0, 1 };

    for (int i = 2; i <= 40; i++){
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }

    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << zero[n] << ' ' << one[n] << endl;
    }
    return 0;
}
