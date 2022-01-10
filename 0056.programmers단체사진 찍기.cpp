//mentoring 56. 2022.1.9
//백트레킹 응용

#include <string>
#include <vector>
using namespace std;

int answer=0;

bool visited[8];
string friends = "ACFJMNRT";
vector<char> v;

void DFS(int cnt, vector<string> data) {
    if (cnt == 8) {
        for (int i = 0; i < data.size();i++) {
            char n1 = data[i][0];
            char n2 = data[i][2];
            char op = data[i][3];
            int dist = data[i][4] - '0';
            dist++;

            int idx1, idx2;
            idx1 = idx2 = -1;
            for (int j = 0; j < 8; j++) {
                if (v[j] == n1) idx1 = j;
                if (v[j] == n2) idx2 = j;
            }
            if (op == '=' && abs(idx1 - idx2) != dist) return;
            if (op == '>' && abs(idx1 - idx2) <= dist) return;
            if (op == '<' && abs(idx1 - idx2) >= dist) return;
        }
        answer++;
        return;
    }
    for (int i = 0; i < 8;i++) {
        if (visited[i]) continue;
        visited[i] = true;
        v.push_back(friends[i]);
        DFS(cnt+1, data);
        visited[i] = false;
        v.pop_back();
    }
}

int solution(int n, vector<string> data) {
    answer = 0;
    DFS(0, data);
    return answer;
}
