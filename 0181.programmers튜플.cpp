//mentoring 181. 2022.3.10
//구현

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 100003
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt[MAX]={0};

    string str="";
    for(int i=0; i<s.size() ; i++){
        if(s[i]-'0'>=0 && s[i]-'0'<=9)
            str+=s[i];
        else if(str.size()){
                cnt[stoi(str)]++;
                str="";
            }
    }

    vector<pair<int,int>> v;
    for(int i=1;i<=100000;i++)
        if(cnt[i])
            v.push_back({cnt[i],i});
    sort(v.begin(),v.end());
    for(int i=v.size()-1; i>=0; i--)
        answer.push_back(v[i].second);

    return answer;
}
