//mentoring 45. 2022.1.4
//다이나믹 프로그래밍 응용

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0, idx=0;
     vector<vector<int>> dp(land.size(), vector<int>(4));
    for(int i=0; i<4; i++)//땅따먹기 시작
             dp[0][i] = land[0][i];

    for(int i=1; i<land.size(); i++){
        for(int j = 0; j < 4; j++){
            int max = 0;
            for(int k = 0; k < 4; k++){//ex_idx
                if (k == j) continue;
                if (max < dp[i - 1][k])
                    max = dp[i - 1][k];
            }
            dp[i][j] = land[i][j] + max;
        }
    }

    for(int i=0; i<4; i++)
        if (answer < dp[land.size()-1][i])
            answer = dp[land.size()-1][i];
    return answer;
}

//초기코드
/*#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0, idx=0;
    for(int i=0; i<4; i++)//땅따먹기 시작
        if(answer<land[0][i]){
            answer=land[0][i];
            idx=i;
        }

    for(int i=1; i<land.size(); i++){
        int max=0;
        int ex_idx=idx;
        for(int j=0; j<4; j++){
            if(max<land[i][j]&&j!=ex_idx){
                max=land[i][j];
                idx=j;
            }
        }
        answer+=max;
    }

    return answer;
}*/
