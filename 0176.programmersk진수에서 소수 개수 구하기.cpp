//mentoring 176. 2022.3.7
//소수 + n진수

#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool prime(long long n) {
    if(n == 1) return false;
    for(long long i=2; i*i<=n; i++)
        if(n%i == 0)
            return false;
    return true;
}

string changeNumber(int n, int k){
    string change="";
    while(n!=0){
        int mod=n%k;
        change=to_string(mod)+change;
        n/=k;
    }
    return change;
}

int solution(int n, int k) {
    int answer = 0;
    string num=changeNumber(n,k);
    vector<string> str;
    stringstream ss(num);
    string s;
    while(getline(ss, s, '0'))
        if(s!="")
            str.push_back(s);

    for(int i=0; i<str.size(); i++)
        if(prime(stoll(str[i])))
            answer++;

    return answer;
}
