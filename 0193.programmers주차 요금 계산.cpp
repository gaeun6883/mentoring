//mentoring 193. 2022.3.19
//구현

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> list;

    for(auto r: records) {//기록 map에 입력
        stringstream ss;
        ss.str(r);
        string time, number, state;
        ss >> time >> number >> state;
        list[number].push_back(time);
    }

    for(auto m: list) {
        if(m.second.size()%2==1)//출차x
            m.second.push_back("23:59");

        vector<string> info = m.second;
        int total = 0;//시간 측정
        for(int i=0; i<info.size()-1; i+=2){
            int in_h = stoi(info[i].substr(0, 2));
            int in_m = stoi(info[i].substr(3, 2));
            int out_h = stoi(info[i+1].substr(0, 2));
            int out_m = stoi(info[i+1].substr(3, 2));
            int time = (out_h-in_h)*60 + (out_m-in_m);
            total+=time;
        }

        int price = fees[1];//가격 도출
        if(total > fees[0])
            price += ceil((total-fees[0]) / (double)fees[2]) * fees[3];

        answer.push_back(price);
    }
    return answer;
}
