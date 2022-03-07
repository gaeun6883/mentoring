//mentoring 174. 2022.3.6
//정렬

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";

    vector<int> v;
    stringstream ss(s);
    string str;
    while(getline(ss,str,' '))
        v.push_back(stoi(str));

    sort(v.begin(), v.end());
    int min=v[0];
    int max=v[v.size()-1];
    answer=to_string(min)+" "+to_string(max);
    return answer;
}
