//mentoring 196. 2022.3.22
//백트레킹

##include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n,m, answer=0;
vector<vector<string>> r;
vector<int> v;
vector<vector<int>> key;

bool check();

void dfs(int idx, int cnt) {
    if (cnt == 0) {
        if(check())
            answer++;
        return;
    }

    for (int i = idx; i < m; i++) {
        v.push_back(i);
        dfs(i + 1, cnt - 1);
        v.pop_back();
    }
    return;
}

int solution(vector<vector<string>> relation) {
    r = relation;
    n = relation.size();
    m = relation[0].size();

    for (int i = 1; i <= m; i++)
        dfs(0, i);

    return answer;
}

bool check(){
    //minimal
    bool isMinimal;
    if (!key.empty()) {
        for (int i = 0; i < key.size(); i++) {
            isMinimal = false;
            for (int j = 0; j < key[i].size(); j++) {
                bool alreadyIn = false;
                for (int k = 0; k < v.size(); k++)
                    if (key[i][j] == v[k])
                        alreadyIn = true;
                    if (!alreadyIn)
                        isMinimal = true;
                }
            if (!isMinimal) return false;
        }
    }

    //unique
    vector<string> cmp;
    bool isUnique = true;
    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < v.size(); j++)
            s += r[i][v[j]];
        cmp.push_back(s);
    }
    sort(cmp.begin(), cmp.end());

    for (int i = 0; i < n - 1; i++)
        if (cmp[i] == cmp[i + 1])
            return false;
    if (isUnique)
        key.push_back(v);

    if(isMinimal&&isUnique) return true;
}
