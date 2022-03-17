//mentoring 189. 2022.3.14
//비트마스크

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (int i = 0; i < numbers.size(); i++){
        long long n = numbers[i];
        if (n % 2 == 0)
            answer.push_back(n + 1);
        else{
            long long x = (n + 1) & (-n);
            long long Result = (n | x) & (~(x >> 1));
            answer.push_back(Result);
        }
    }
