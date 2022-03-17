//mentoring 186. 2022.3.12
//greedy algorithm

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer="";
    int idx = -1;
    for(int i = 0; i <number.length() - k; i++) {
        char max='0';
        for(int j = idx + 1; j <= k + i; j++)
            if(number[j] > max) {
                max = number[j];
                idx = j;
            }
        answer += max;
    }
    return answer;
}
