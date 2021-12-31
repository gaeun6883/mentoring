//mentoring 40.2021.12.30
//배열을 이용한 구현

#include <string>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    bool visitX[10][11]={false, };
    bool visitY[11][10]={false, };
    int meX=5, meY=5;

    for(int i=0; i<dirs.length(); i++){
        char go=dirs[i];
        if(go=='U'){
            if(meY==0) continue;
            meY--;
            if(!visitY[meX][meY]){
                visitY[meX][meY]=true;
                answer++;
            }
        }
        if(go=='D'){
            if(meY==10) continue;
            if(!visitY[meX][meY]){
                visitY[meX][meY]=true;
                answer++;
            }
            meY++;
        }
        if(go=='R'){
            if(meX==10) continue;
            if(!visitX[meX][meY]){
                visitX[meX][meY]=true;
                answer++;
            }
            meX++;
        }
        if(go=='L'){
            if(meX==0) continue;
            meX--;
            if(!visitX[meX][meY]){
                visitX[meX][meY]=true;
                answer++;
            }
        }
    }
    return answer;
}
