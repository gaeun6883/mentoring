//mentoring 185. 2022.3.12
//greedy algorithm

#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int s=name.size();
    int move = s;
    for(int i=0; i<s;i++){
        if(name[i]<'N')
            answer += name[i]-'A';
        else answer += 'Z' - name[i]+1;

        int A_idx = i+1;
        while(A_idx < s && name[A_idx] =='A')
            A_idx++;
        int x=i+(s-A_idx)+min(i,s-A_idx);
        move = min(move, x);
    }
    answer+=move;
    return answer;
}
