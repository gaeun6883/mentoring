//mentoring 198. 2022.3.24
//백트레킹

#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;
int arr[26];
string order;

void dfs(int cnt, int idx, string s) {
    if (cnt == 0) {
        m[s]++;
        arr[s.size()-1]=max(arr[s.size()-1], m[s]);
        return;

    for(int i=idx+1; i<order.size(); i++) {
        s += order[i];
        dfs(cnt-1, i, s);
        s=s.substr(0,s.length()-1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int i=0; i<course.size(); i++) {
        for(int j=0; j<orders.size(); j++) {
            sort(orders[j].begin(), orders[j].end());
            order=orders[j];
            dfs(course[i], -1, "");
        }

        for(auto menu: m)
            if (course[i]==menu.first.length())
                if ((menu.second>1) && (arr[menu.first.length()-1]==menu.second))
                    answer.push_back(menu.first);
    }

    sort(answer.begin(), answer.end());
    return answer;
}
