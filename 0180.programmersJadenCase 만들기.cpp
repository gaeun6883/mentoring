//mentoring 180. 2022.3.9
//대소문자 변환

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' ')
            if(s[i-1] == ' ' || i == 0){
               if('a' <= s[i] && s[i] <= 'z')
                s[i] = s[i]-'a'+'A';
            }
            else if('A' <= s[i] && s[i] <= 'Z')
                s[i] = s[i]-'A'+'a';
        answer += s[i];
    }
    return answer;
}
