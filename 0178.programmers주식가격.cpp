//mentoring 178. 2022.3.8
//구현

#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0; i<prices.size()-1; i++){
        int t = 0;
        for(int j=i+1; j<prices.size(); j++){
            t++;
            if(prices[i] > prices[j])
                break;
        }
        answer.push_back(t);
    }
    answer.push_back(0);
    return answer;
}
