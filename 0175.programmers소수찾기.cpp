//mentoring 175. 2022.3.7
//소수 + n진수

#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> v;
bool check[8]={false, };

bool prime(long long n) {
    if(n == 1) return false;
    for(long long i=2; i*i<=n; i++)
        if(n%i == 0)
            return false;
    return true;
}

void dfs(string s, string numbers){
    if(!s.empty()) v.push_back(stoi(s));

    for(int i=0; i<numbers.length(); i++)
        if(!check[i]){
            check[i]=true;
            dfs(s+=numbers[i],numbers);
            check[i]=false;
            s.pop_back();
        }
}

int solution(string numbers) {
    int answer = 0;

    string s="";
    dfs(s, numbers);
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
        if(v[i]==v[i-1]) continue;
        else if(prime(v[i]))
            answer++;
    return answer;
}

//code.mento
/*void func(int k,string s){
    if(k==N){
        if(s!=""&&isprime(stoi(s))&&(find(prime.begin(),prime.end(),stoi(s))==prime.end())){
            answer++;
            prime.push_back(stoi(s));
        }
        return;
    }
    for(int i=0;i<v.size();i++){
        if(!visited[i]){
            visited[i]=true;
            func(k+1,s);
            func(k+1,s+v[i]);
            visited[i]=false;
        }
    }
}

int solution(string numbers) {
    N=numbers.length();
    for(int i=0;i<N;i++){
        v.push_back(numbers[i]);
    }
    func(0,"");

    return answer;
}*/
