//mentoring 39. 2021.12.30
//map의 사용

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> alpha;
    for(int i=0; i<26; i++){
        string tmp(1,('A'+i));
        alpha.insert(make_pair(tmp, i+1));
    }

    int idx=26;
    string s1, s2;
    for(int i=0; i<msg.size();i++){
        s1=s2=msg[i];
        for(int j=i+1; j<msg.size();j++){
            s2+=msg[j];
            if(alpha.count(s2)==0){
                alpha.insert({s2,++idx});
                answer.push_back(alpha[s1]);
                break;
            }
            i++;
            s1=s2;
        }
    }
    answer.push_back(alpha[s1]);
    return answer;
}
