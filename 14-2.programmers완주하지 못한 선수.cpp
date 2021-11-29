//mentoring 14. 2021.11.17
//unordered_map의 사용

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> map;
    for(int i=0; i<participant.size(); i++){
        string name=participant[i];
        map[name]++;
    }
    for(int j=0; j<completion.size(); j++){
        string name=completion[j];
        map[name]--;
    }
    for(auto k: map){
        if(k.second>0){
            answer=k.first;
            break;
        }
    }
    return answer;
}

//멘토님 코드
/*#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> h;
    for(string c:completion){
        h[c]++;
    }
    for(string p:participant){
        if(h.end()==h.find(p)){
            answer=p;
            break;
        }
        else{
            h[p]--;
            if(h[p]<0){
                answer=p;
                break;
            }
        }
    }
    return answer;
  }*/
