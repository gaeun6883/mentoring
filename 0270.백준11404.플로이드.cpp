//mentoring 270. 2022.7.17
//플루이드 와셜

#include <iostream>
#include <cstring>
#include <climits>
#define MAX 987654321
using namespace std;

int arr[105][105];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            arr[i][j] = MAX;
    for (int i = 1; i <= n; i++)
        arr[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (arr[a][b] > c)
            arr[a][b] = c;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (arr[i][j] == MAX) cout << "0 ";
            else cout << arr[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
