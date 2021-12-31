//mentoring 2021.12.29
//다이나믹 프로그래밍 응용

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int N=board.size();
    int M=board[0].size();
    int answer=0;
    bool state=false;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!board[i][j])
                continue;
            state=true;
            if(i-1<0||j-1<0)
                continue;
            board[i][j]=min(board[i][j-1],min(board[i-1][j],board[i-1][j-1]))+1;
            answer=max(board[i][j],answer);
        }
    }
    if(state==true&&answer==0)
        answer=1;
    return answer*answer;
}

//초기코드
/*int solution(vector<vector<int>> board)
{
    int N=board.size();
    int M=board[0].size();
    int answer = 0;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(!board[i][j])
                continue;
            board[i][j] += min(board[i-1][j-1], min(board[i][j-1], board[i-1][j]))+1;
            answer=max(answer,board[i][j]);
        }
    }

    return answer*answer;
}*/
