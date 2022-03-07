//mentoring 173. 2022.3.6
//정렬

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    for(int i=0; i<numbers.size(); i++)
        str.push_back(to_string(numbers[i]));
    sort(str.begin(), str.end(), compare);

    if(str[0]=="0") return "0";
    for(int i=0; i<numbers.size(); i++)
        answer+=str[i];
    return answer;
}
