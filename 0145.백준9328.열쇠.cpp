//mentoring 145. 2022.2.19
//bfs

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define MAX 103
using namespace std;

int h, w, visited[MAX][MAX], alpha[26], result = 0;
char map[MAX][MAX];
string str;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void reset();
void bfs() {
    queue<pair<int, int>> q;
    queue<pair<int, int>> door[26];
    q.push({ 0,0 });
    visited[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (map[nx][ny] == '*' || visited[nx][ny]) continue;
            visited[nx][ny] = 1;

            if ('A' <= map[nx][ny] && map[nx][ny] <= 'Z')
                if (alpha[map[nx][ny] - 'A'])
                    q.push({ nx, ny });
                else door[map[nx][ny] - 'A'].push({ nx, ny });

            else if ('a' <= map[nx][ny] && map[nx][ny] <= 'z') {
                q.push({ nx, ny });
                if (!alpha[map[nx][ny] - 'a']) {
                    alpha[map[nx][ny] - 'a'] = 1;
                    while (!door[map[nx][ny] - 'a'].empty()) {
                        q.push(door[map[nx][ny] - 'a'].front());
                        door[map[nx][ny] - 'a'].pop();
                    }
                }
            }
            else {
                q.push({ nx, ny });
                if (map[nx][ny] == '$')
                    result++;
            }
        }
    }
}

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define MAX 103
using namespace std;

int h, w, visited[MAX][MAX], alpha[26], result = 0;
char map[MAX][MAX];
string str;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void reset();
void bfs() {
    queue<pair<int, int>> q;
    queue<pair<int, int>> door[26];
    q.push({ 0,0 });
    visited[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= h+2 || ny >= w+2) continue;
            if (map[nx][ny] == '*' || visited[nx][ny]) continue;

            visited[nx][ny] = true;

            if ('A' <= map[nx][ny] && map[nx][ny] <= 'Z') {
                if (alpha[map[nx][ny] - 'A'])
                    q.push({ nx, ny });
                else
                    door[map[nx][ny] - 'A'].push({ nx, ny });
            }
            else if ('a' <= map[nx][ny] && map[nx][ny] <= 'z') {
                q.push({ nx, ny });
                if (!alpha[map[nx][ny] - 'a']) {
                    alpha[map[nx][ny] - 'a'] = 1;
                    while (!door[map[nx][ny] - 'a'].empty()) {
                        q.push(door[map[nx][ny] - 'a'].front());
                        door[map[nx][ny] - 'a'].pop();
                    }
                }
            }
            else {// '.','$'
                q.push({ nx, ny });
                if (map[nx][ny] == '$')
                    result++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> h >> w;
        reset();

        for (int i = 0; i < h + 2; i++) {
            for (int j = 0; j < w + 2; j++) {
                map[i][j] = '.';
            }
        }

        for (int i = 1; i <= h; i++) {
            string tmp;
            cin >> tmp;
            for (int j = 1; j <= w; j++) {
                map[i][j] = tmp[j - 1];
            }
        }

        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '0')
                continue;
            alpha[str[i] - 'a'] = 1;
        }

        bfs();

        //map과 visited배열 상태 확인 코드
        /*for (int i = 0; i < h + 2; i++) {
            for (int j = 0; j < w + 2; j++) {
                cout << map[i][j] << " ";
            }
            cout << "\n";
        }

        for (int i = 0; i < h + 2; i++) {
            for (int j = 0; j < w + 2; j++) {
                cout << visited[i][j] << " ";
            }
            cout << "\n";
        }*/

        cout << result << "\n";
    }
}

void reset() {
    result = 0;
    str = "";
    for (int i = 0; i < h+2; i++)
        for (int j = 0; j < w+2; j++)
            visited[i][j] = 0;
    for (int i = 0; i < 26; i++)
        alpha[i] = 0;
}
//초기 main 코드
/*int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> h >> w;
        reset();
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> map[i][j];
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '0') continue;
            alpha[str[i] - 'a'] = 1;
        }

        bfs();

        cout << result << "\n";
    }
}*/

void reset() {
    result = 0;
    str = "";
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            visited[i][j] = 0;
    for (int i = 0; i < 26; i++)
        alpha[i] = 0;
}
