//mentoring 17. 2021.11.20
//map의 사용

#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> music;//장르 : 총 횟수
    map<string, map<int,int>> mlist;//장르 : (고유번호 : 플레이횟수)
    for(int i=0; i<genres.size(); i++){
        music[genres[i]]+=plays[i];
        mlist[genres[i]][i]=plays[i];
    }

    while(music.size()>0){
        //가장 많이 재생된 장르
        string mGenre;
        int max=0;
        for(auto n:music){
            if(max<n.second){
                max=n.second;
                mGenre=n.first;
            }
        }

        //장르내 재생순위 높은 것 2가지
        for(int i=0; i<2; i++){
            int data=0, index=-1;//data: 재생번호, index: 고유번호
            for(auto m: mlist[mGenre]){
                if(data<m.second){
                    data=m.second;
                    index=m.first;
                }
            }

            if(index==-1)
                break;
            answer.push_back(index);
            mlist[mGenre].erase(index);
        }
        music.erase(mGenre);
    }
    return answer;
}
