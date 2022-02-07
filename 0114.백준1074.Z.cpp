//mentoring 114. 2022.2.4
//dfs알고리즘, 분열탐색

#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int dx[] = { 0, 0, 1, 1 };
int dy[] = { 0, 1, 0, 1 };
int result, cnt=0;

void solution(int x, int y, int size) {
    if (size == 1){
        if (x <= r && x + 1 >= r && y <= c && y + 1 >= c) {
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx == r && ny == c) {
                    result = cnt;
                    return;
                }
                cnt++;
            }
        }
        else cnt += 4;
    }
    else {
        int Size = pow(2, size);
        int s = pow(2, size - 1);
        if (x <= r && y <= c && x + Size >= r && y + Size >= c) {
            solution(x, y, size - 1);
            solution(x, y + s, size - 1);
            solution(x + s, y, size - 1);
            solution(x + s, y + s, size - 1);
        }
        else cnt += Size*Size;
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> c;

	solution(0, 0, n);
    cout << result;

	return 0;
}

//초기코드
/*void solution(int x, int y, int size) {
    if (size == 2) {
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx == r && ny == c) {
                result = cnt;
                return;
            }
            cnt++;
        }
        return;
    }

    solution(x, y, size - 1);
    solution(x, y + s, size - 1);
    solution(x + s, y, size - 1);
    solution(x + s, y + s, size - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> c;

    solution(0, 0, n);
    cout << result;

    return 0;
}*/
