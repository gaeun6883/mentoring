//mentoring 190. 2022.3.15
//구현-참고: 백준 Puyo Puyo

#include <string>
#include <vector>
#include <queue>
#include <utility>
#define MAX 33
using namespace std;

vector<string> map;
int visited[MAX][MAX];
int M, N;
int dx[] = { 0, 1, 1 };
int dy[] = { 1, 0, 1 };

bool bfs(int x, int y){
    for (int i = 0; i < 3; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= M || ny >= N )
            return false;
        if (map[x][y] != map[nx][ny]) return false;
    }
    return true;
}

int remove(queue<pair<int, int>> Q){
    int cnt=0;
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        if (map[x][y] != '.'){
            map[x][y] = '.';
            cnt++;
        }
        for (int j = 0; j < 3; j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (map[nx][ny] != '.'){
                cnt++;
                map[nx][ny] = '.';
            }
        }
    }
    return cnt;
}

void next_setting(){
    for (int j = 0; j < N; j++)
      while (true) {
         bool state = false;
         for (int i = M-1; i > 0; i--)
            if (map[i][j] == '.' && map[i - 1][j] != '.') {
               map[i][j] = map[i - 1][j];
               map[i - 1][j] = '.';
               state = true;
            }
         if (!state) break;
      }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    M=m;
    N=n;
    map=board;
    while (true){
        bool state = false;
        queue<pair<int, int>> q;
          for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                visited[i][j] = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (map[i][j] == '.') continue;
                if (bfs(i, j)){
                    q.push({i, j});
                    state = true;
                }
            }
        }

        if (!state) break;
        answer += remove(q);
        next_setting();
    }
    return answer;
}
