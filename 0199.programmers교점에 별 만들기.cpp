//mentoring 199. 2022.3.25
//구현

#include <string>
#include <vector>
#include <map>
#include <climits>
#include <utility>
#include <algorithm>
#define max(x,y) x>y?x:y
#define min(x,y) x>y?y:x
using namespace std;

vector<pair<long long , long long> > v;
map<pair<long long,long long>, int> m;

void make_m(vector<int>& v1, vector<int>& v2){
    long long bottom = v1[0] * v2[1] - v1[1] * v2[0];
    if(bottom == 0) return;
    long long topX = (long long)v1[1] * v2[2] - (long long)v1[2] * v2[1];
    long long topY = (long long)v1[2] * v2[0] - (long long)v1[0] * v2[2];

    long long x = topX / bottom;
    long long y = topY / bottom;

    if( topX % bottom == 0 && topY % bottom == 0)
        if(m.count({x,y}) == 0)
            m[{x,y}] = 1;
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    for(int i=0;i<line.size()-1;i++)
        for(int j=i+1;j<line.size();j++)
            make_m(line[i], line[j]);

    auto x = m.begin();
    while(x != m.end()){
        v.push_back({x->first.first, x->first.second});
        x++;
    }

    long long maxX = LLONG_MIN, minX = LLONG_MAX, maxY = LLONG_MIN, minY = LLONG_MAX;
    for(int i=0;i<v.size();i++){
        maxX = max(maxX, v[i].first);
        minX = min(minX, v[i].first);
        maxY = max(maxY, v[i].second);
        minY = min(minY, v[i].second);
    }

    string str;
    for(int j=0;j<maxX-minX+1;j++)
            str+=".";
    for(int i=0;i<maxY-minY+1;i++)
        answer.push_back(str);
    for(int i=0;i<v.size();i++)
        answer[abs(v[i].second - maxY)][abs(v[i].first - minX)]='*';
    return answer;
}
