//mentoring 20. 2021.11.24
//string

#include <string>
#include <vector>
using namespace std;
#define min(x, y) (x<y)?x:y

int solution(string s) {
    int answer = s.length();
    for (int i = 1; i <= s.length() / 2; i++) {
        string result;
        string first=s.substr(0, i);
        int cnt=1;
        for(int j=i; j<=s.length(); j+=i){
            string second=s.substr(j, i);
            if(first==second)
                cnt++;
            else{
                if(cnt==1)
                    result+=first;
                else
                    result+=to_string(cnt)+first;
                first=second;
                cnt=1;
            }
        }
        if(cnt==1)
            result+=first;
        else
            result+=to_string(cnt)+first;
        answer=min(answer,result.length());
    }

    return answer;
}
