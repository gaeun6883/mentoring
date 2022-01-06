//mentoring 51. 2022.1.6
//bfs응용

#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dist[5][5];

int right_distance(vector<string> place){
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            if(place[i][j] != 'P')  continue;

            for(int i=0;i<5;i++)
                for(int j=0;j<5;j++)
                    dist[i][j]=-1;

            queue< pair<int, int> > q;//bfs
            dist[i][j] = 0;
            q.push({i, j});
            while(!q.empty()) {
                pair<int,int> cur = q.front();
                q.pop();
                for(int dir=0;dir<4;dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(!(nx>=0&& nx<5 && ny>=0 && ny<5)) continue;
                    if(dist[nx][ny] == -1 && place[nx][ny] != 'X') {
                        dist[nx][ny] = dist[cur.first][cur.second] + 1;
                        q.push({nx, ny});
                    }
                }
            }

            for(int i=0;i<5;i++)
                for(int j=0;j<5;j++)
                    if((dist[i][j] ==1||dist[i][j] == 2) && place[i][j] == 'P')
                            return 0;
            }
        }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0; i<places.size(); i++){
        int n=right_distance(places[i]);
        answer.push_back(n);
    }
    return answer;
}
