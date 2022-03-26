//mentoring 195. 2022.3.21
//구현

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> make_v(string str){
    vector<string> v;
    string tmp;
    for(int i=1; i<str.length(); i++)
        if(isalpha(str[i-1]) && isalpha(str[i])){
            tmp = "";
            tmp += toupper(str[i-1]);
            tmp += toupper(str[i]);
            v.push_back(tmp);
        }
    return v;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v1 = make_v(str1);
    vector<string> v2 = make_v(str2);

    if(v1.empty() && v2.empty()) return 65536;

    int same = 0;
    for(int i=0; i<v1.size(); i++){
        auto it = find(v2.begin(), v2.end(), v1[i]);
        if(it!=v2.end()){
            v2.erase(it);
            same++;
        }
    }

    answer=65536.0 * (same/(double)(v1.size()+v2.size()));
    return answer;
}
