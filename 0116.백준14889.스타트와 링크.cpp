//mentoring 2022.2.5
//백트래킹

#include <iostream>
#include <climits>
#define MAX 23
using namespace std;

int n, s[MAX][MAX];
int visited[MAX] = { 0, };
int arr1[MAX], arr2[MAX];
int result = INT_MAX;

void dfs(int cur, int cnt) {
    if (cnt == n / 2) {
        int start = 0, link = 0;
        int idx = 0;
        for (int i = 1; i <= n; i++)
            if (!visited[i])
                arr2[idx++] = i;
        for (int i = 0; i < n / 2; i++)
            for (int j = 1; j <= n; j++) {
                if (arr1[i] != j && visited[j])
                    start += s[arr1[i]][j];
                if (arr2[i] != j && !visited[j])
                    link += s[arr2[i]][j];
            }
        result = min(result, abs(link - start));
        return;
    }
    //dfs
    for (int i = cur + 1; i <= n; i++)
        if (!visited[i]) {
            visited[i] = 1;
            arr1[cnt] = i;
            dfs(i, cnt + 1);
            visited[i] = 0;
        }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> s[i][j];

    dfs(0, 0);
    cout << result;
    return 0;
}
