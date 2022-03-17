//mentoring 184. 2022.3.11
//string 함수

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize==0)
        return 5*cities.size();

    vector<string> v;
    for(int i=0; i<cities.size(); i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        auto s = find(v.begin(), v.end(), cities[i]);
        if (s == v.end()){
            if (v.size() < cacheSize)
                v.push_back(cities[i]);
            else {
                v.erase(v.begin());
                v.push_back(cities[i]);
            }
            answer+=5;
        }
        else {
            v.erase(s);
            v.push_back(cities[i]);
            answer+=1;
        }
    }
    return answer;
  }
