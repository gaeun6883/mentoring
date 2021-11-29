//mentoring 21. 2021.11.25
//stringstream 사용

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> user_id;
    unordered_map<string, string> nick; // 유저 아이디 : 닉네임
    string order, id, nickname;

    for(int i=0; i<record.size(); i++){
        stringstream ss;
        ss.str(record[i]);
        ss >> order;
        if(order == "Enter"){
            ss >> id >> nickname;
            user_id.push_back(id);
            answer.push_back("님이 들어왔습니다.");
            nick[id] = nickname;
        }
        else if (order == "Leave") {
            ss >> id;
            user_id.push_back(id);
            answer.push_back("님이 나갔습니다.");
        }
        else {//Chage
            ss >> id >> nickname;
            nick[id] = nickname;
        }
    }

    for(int i=0; i<answer.size(); i++){
        answer[i] = nick[user_id[i]] + answer[i];
    }

    return answer;
}
