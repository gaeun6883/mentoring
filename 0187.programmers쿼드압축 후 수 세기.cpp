//mentoring 187. 2022.3.13
//분할 정복

#include <string>
#include <vector>

using namespace std;

vector<int> answer(2, 0);
vector<vector<int>> map;

void dfs(int x, int y, int size){
    bool zero=true, one=true;
    for (int i = x; i < x + size; i++)
        for (int j = y; j < y + size; j++)
            if (!map[i][j]) one = false;
            else zero = false;

    if (zero){
        answer[0]++;
        return;
    }
    if (one){
        answer[1]++;
        return;
    }

    dfs(x, y, size / 2);
    dfs(x, y + size / 2, size / 2);
    dfs(x + size / 2, y, size / 2);
    dfs(x + size / 2, y + size / 2, size / 2);
}

vector<int> solution(vector<vector<int>> arr) {
    map=arr;
    dfs(0, 0, arr.size());
    return answer;
}
