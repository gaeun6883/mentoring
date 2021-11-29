//mentoring 23. 2021.11.27
//bfs응용

#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define max(x,y) x>y?x:y

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
bool visited[102][102]={false, };

int BFS(int m, int n, int x, int y, vector<vector<int>> picture) {
    visited[x][y] = true;
    int size = 1;
    int target = picture[x][y];
    queue<pair<int, int>> q;
    q.push({x,y});

    while (!q.empty()) {
        pair<int, int> cur=q.front();
        q.pop();
        for (int i = 0; i < 4;i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (!visited[nx][ny] && picture[nx][ny] == target) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    size++;
                }
            }
        }
    }
    return size;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i=0; i<m; i++)
      for(int j=0; j<n; j++)
          visited[i][j]=false;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
           if (!visited[i][j] && picture[i][j] != 0) {
                int size = BFS(m, n, i, j, picture);
                max_size_of_one_area = max(max_size_of_one_area, size);
                number_of_area++;
           }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
