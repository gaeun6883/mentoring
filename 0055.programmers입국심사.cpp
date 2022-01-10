//mentoring 55. 2022.1.8
//이진탐색 응용

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long binary_search(vector<int> times, int n){
    long long left=1, right=times[times.size()-1]*n;
    long long result=0;
    while(left<=right){
        long long middle=(left+right)/2;
        long long cnt=0;
        for(int i=0;i < times.size(); i++)
            cnt += middle / times[i];
        if(cnt<n)
            left=middle+1;
        else{
            if(middle<=right)
                result=middle;
            right=middle-1;
        }
    }
    return result;
}
long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    answer=binary_search(times, n);
    return answer;
}
