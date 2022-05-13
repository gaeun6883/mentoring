//mentoring 230. 2022.5.12
//구현

#include <iostream>
#include <algorithm>
#include <climits>
#define MAX 22
using namespace std;

int n, map[MAX][MAX], result = INT_MAX;
int sol(int i, int j, int x, int y);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    for (int i = 0; i < n ; i++)
        for (int j = 1; j < n ; j++)
            for (int x = 1; x < n; x++)
                for (int y = 1; y < n ; y++) {
                    if (i + x + y > n) continue;
                    if (j - x <= 0 || j + y > n) continue;
                    result=min(result,sol(i, j, x, y));
                }

    cout << result;
    return 0;
}

int sol(int a, int b, int x, int y) {
    int v[5] = { 0, };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i < a + x && j <= b && !(i >= a && j >= b - (i - a)))//1�� ���ű�
                v[0] += map[i][j];
            else if (i <= a + y && j > b && !(i >= a && j <= b + (i - a))) //2�� ���ű�
                v[1] += map[i][j];
            else if (i >= a + x && j < b - x + y && !(i <= a + x + y && j >= b - x + y + (i - (a + x + y))))//3�� ���ű�
                v[2] += map[i][j];
            else if (i > a + y && j >= b - x + y && !(i <= a + x + y && j <= b - x + y - (i - (a + x + y)))) //4�� ���ű�
                v[3] += map[i][j];
            else v[4] += map[i][j];//5�� ���ż�

    sort(v, v + 5);
    return v[4] - v[0];
}
