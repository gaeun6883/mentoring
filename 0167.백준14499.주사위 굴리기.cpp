//mentoring 167. 2022.3.3
//구현 

#include <iostream>
#define MAX 22
using namespace std;

int n, m, x, y, k, map[MAX][MAX], comand[1002];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int dice[7] = { 0 };

void roll(int d);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    for (int i = 0; i < k; i++)
        cin >> comand[i];

    int curX = x, curY = y;
    for (int i = 0; i < k; i++) {
        int dir = comand[i] - 1;
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

        roll(dir);

        if (!map[nx][ny])
            map[nx][ny] = dice[6];
        else {
            dice[6] = map[nx][ny];
            map[nx][ny] = 0;
        }
        cout << dice[1] << "\n";

        curX = nx;
        curY = ny;
    }
    return 0;
}

void roll(int d) {
    int d1, d2, d3, d4, d5, d6;
    d1 = dice[1], d2 = dice[2], d3 = dice[3], d4 = dice[4], d5 = dice[5], d6 = dice[6];
    if (d == 0) {
        dice[1] = d4;
        dice[4] = d6;
        dice[6] = d3;
        dice[3] = d1;
    }
    else if (d == 1) {
        dice[4] = d1;
        dice[6] = d4;
        dice[3] = d6;
        dice[1] = d3;
    }
    else if (d == 2) {
        dice[1] = d5;
        dice[2] = d1;
        dice[6] = d2;
        dice[5] = d6;
    }
    else if (d == 3) {
        dice[5] = d1;
        dice[1] = d2;
        dice[2] = d6;
        dice[6] = d5;
    }
}
