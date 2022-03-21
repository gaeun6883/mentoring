//mentoring 192. 2022.3.18
//구현

#include <string>
#include <vector>
#include <algorithm>
#define MAX 505
using namespace std;

vector<string> grids;
int n, m, visited[MAX][MAX][4]={0,};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int action(int x, int y, int d){
    int cnt = 0;
    while(true){
        visited[x][y][d] = 1;
        x = (x + dx[d] + n) % n;
        y = (y + dy[d] + m) % m;
        cnt++;

        if(grids[x][y] == 'L')
            d = (d + 3) % 4;
        else if(grids[x][y] == 'R')
            d = (d + 1) % 4;

        if(visited[x][y][d]) break;
    }
    return cnt;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    grids=grid;
    n=grid.size();
    m=grid[0].size();

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            for(int dir=0; dir<4; dir++)
                if(!visited[i][j][dir])
                    answer.push_back(action(i, j, dir));
    sort(answer.begin(), answer.end());
    return answer;
}
