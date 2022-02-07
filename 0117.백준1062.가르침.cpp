//mentoring 117. 2022.2.6
//백트래킹

#include <iostream>
#include <string>
#define MAX 53
using namespace std;

int n, k, result;
string arr[MAX];
int visited[26];

void solution(int cur, int cnt){
    if (cnt == k){
        int tmp = 0;
        for (int i = 0; i < n; i++){
            bool flag = true;
            for (int j = 0; j < arr[i].length(); j++)
                if (!visited[arr[i][j] - 'a']){
                    flag = false;
                    break;
                }
            if (flag)
                tmp++;
        }
        result = max(result, tmp);
        return;
    }

    for (int i = cur; i < 26; i++)
        if (!visited[i]){
            visited[i] = 1;
            solution(i, cnt + 1);
            visited[i] = 0;
        }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i] = arr[i].substr(4, arr[i].length());
        for (int j = 0; j < 4; j++)
            arr[i].pop_back();
    }

    visited['a' - 'a'] = 1;
    visited['c' - 'a'] = 1;
    visited['i' - 'a'] = 1;
    visited['n' - 'a'] = 1;
    visited['t' - 'a'] = 1;

    k = k - 5;
    solution(0, 0);
    cout << result << "\n";

    return 0;
}
