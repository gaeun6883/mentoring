//mentoring 172. 2022.3.5
//n진수 응용

#include <string>
#include <vector>
#include <string>
using namespace std;

string solution(int n) {
    string answer = "";
    string num="412";
    while (n > 0) {
        int mod=n%3;
        n=n/3;
        answer = num[mod]+answer;
        if(mod== 0) n -= 1;
    }
    return answer;
}
