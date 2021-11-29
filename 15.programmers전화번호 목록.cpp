//mentoring 14. 2021.11.18
//unordered_map의 사용

#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> list;//굳이 map을 사용할 필요없음. unordered_map의 사용 시 정렬시간 줄어듬.
    for(string n: phone_book)
        list[n]=1;

    for(string number : phone_book)
        for(int i = 0; i < number.length(); i++)
            if(list.find(number.substr(0,i)) != list.end())
                return false;
    return answer;
}
