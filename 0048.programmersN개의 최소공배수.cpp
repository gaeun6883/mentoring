//mentoring 48. 2022.1.6
//최소공배수

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int max = *max_element(arr.begin(),arr.end());
    int n = 0;
    bool flag=false;
    while(!flag){
        flag=true;
        answer=max*(++n);
        for(int i = 0; i<arr.size(); i++){
            if(answer%arr[i] != 0){
                flag = false;
                break;
            }
        }
    }
    return answer;
}
