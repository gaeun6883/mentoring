//mentoring 32. 2021.12.26
//string 함수 응용

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct music{
    int idx;
    int time;
    string title;
}music;
vector<music> list;//<시간,제목>

string changeMelody(string m){
while(true){
        int idx=m.find("#");
        if(idx==-1)
            break;
        char c=tolower(m[idx-1]);
        m.replace(idx-1,2,string(1,c));
    }
    return m;
}

bool compareRule(music a, music b) {
    if (a.time == b.time)
        return a.idx < b.idx;
    return a.time > b.time;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";

    m=changeMelody(m);

    for(int i=0; i<musicinfos.size();i++){
        //시간
        int start = stoi(musicinfos[i].substr(0, 2)) * 60 + stoi(musicinfos[i].substr(3, 2));
        int finish = stoi(musicinfos[i].substr(6, 2)) * 60 + stoi(musicinfos[i].substr(9, 2));
        int time=finish-start;

        //제목, 음계
        string musicInfo=musicinfos[i].substr(12);
        int comma=musicInfo.find(',');
        string title=musicInfo.substr(0,comma);
        string melody=musicInfo.substr(comma+1);
        melody=changeMelody(melody);

        //음계비교
        string totalM="";
        if(melody.length()>=time)
            totalM=melody.substr(0,time);
        else{
            int repeatCnt=time/melody.length();
            for(int j=0; j<repeatCnt; j++)
                totalM+=melody;
            int remain=time%melody.length();
            totalM+=melody.substr(0,remain);
        }

        int idx=totalM.find(m);
        if(idx!=-1)
            list.push_back({i, time, title});
    }

    //결과도출
    if(list.empty())
        return answer;
    if(list.size()>1)
        sort(list.begin(), list.end(), compareRule);
    answer=list[0].title;
    return answer;
}
