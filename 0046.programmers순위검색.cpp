//mentoring 46. 2021.1.4
//sstream 응용

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, vector<int>> applicantL;//<full, divide>

void make_info(string c[5]) {
    string s = "";
    for (int i = 0; i < (1 << 4); i++) {
        s = "";
        for (int j = 0; j < 4; j++)
            if (i & (1 << j)) s += c[j];
            else s += '-';
        applicantL[s].push_back(stoi(c[4]));
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for (int i = 0; i < info.size(); i++) {//지원자 조건 정리
        stringstream stream(info[i]);
        string condition[5];
        stream >> condition[0] >> condition[1] >> condition[2] >> condition[3] >> condition[4];
        make_info(condition);
    }

    for (auto& score : applicantL)
       sort(score.second.begin(), score.second.end());

    for (int i = 0; i < query.size(); i++) {//query 정리
        stringstream stream(query[i]);
        string condition[5];
        string a;
        stream >> condition[0] >> a >> condition[1] >> a >> condition[2] >> a >> condition[3] >> condition[4];
        vector<int> v = applicantL[condition[0] + condition[1] + condition[2] + condition[3]];

        if (v.size() != 0) {
            auto it = lower_bound(v.begin(), v.end(), stoi(condition[4]));
            answer.push_back(v.size() - (it - v.begin()));
        }
        else answer.push_back(0);
    }
    return answer;
}
