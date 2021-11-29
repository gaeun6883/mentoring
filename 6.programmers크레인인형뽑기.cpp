//mentoring 6. 2021.11.7
//vector대신 stack 사용가능

#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> result;

    for(int i=0; i<moves.size(); i++){
        int y=moves[i]-1;
        int x=0;
        for(int j=board.size()-1; j>=0; j--){
            if(board[j][y]!=0)
                x=j;
        }

        if(board[x][y]!=0){
            if(result.size()==0)
                result.push_back(board[x][y]);
						else if(result.back()==board[x][y]){
							answer+=2;
							result.pop_back();
					}
					else
							result.push_back(board[x][y]);
					board[x][y]=0;
				}
	}
	return answer;
}
