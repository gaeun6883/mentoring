//mentoring 204. 2022.3.30
//dfs

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char map[5][5];
int visited[25], result = 0;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1 ,0, 0 };

bool check();
void dfs(int idx, int cnt) {
	if (cnt == 7) {
		if (check())
			result++;
		return;
	}

	for (int i = idx; i < 25; i++){
		if (!visited[i]) {
			visited[i] = true;
			dfs(i, cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 5; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 5; j++)
			map[i][j] = s[j];
	}

	dfs(0, 0);
	cout << result;
	return 0;
}

bool check() {
	bool isSeven = false;
    queue <pair<int, int>> q;
    bool c[5][5] = { false, }, que[5][5] = { false, };
    bool tmp = false;
    for (int i = 0; i < 25; i++){
        if (visited[i]){
            int x = i / 5;
            int y = i % 5;
            c[x][y] = true;
            if (!tmp){
                q.push({ x, y });
                que[x][y] = true;
                tmp=true;
            }
        }
    }

    int wCnt = 1;
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (wCnt == 7) {
            isSeven = true;
            break;
        }
        for (int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if (c[nx][ny] && !que[nx][ny]) {
                que[nx][ny] = true;
                q.push({nx, ny});
                wCnt++;
            }
        }
    }
		if(!isSeven) return false;

	bool isFour = false;//S�� 4�� �̻��ΰ�?
	int cnt = 0;
	for (int i = 0; i < 25; i++)
		if (visited[i])
			if (map[i/5][i%5] == 'S')
				cnt++;
	if (cnt >= 4) isFour=true;

	if (isSeven && isFour) return true;
	else return false;
}
