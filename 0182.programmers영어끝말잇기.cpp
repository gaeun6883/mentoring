//mentoring 182. 2022.3.10
//구현

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> sol(int num, int n){
    if((num+1)%n==0)
        return {n, (num+1)/n};
    else  return {(num+1)%n, (num+1)/n+1};
}

vector<int> solution(int n, vector<string> words) {
    char back = words[0][words[0].size()-1];
    for(int i=1; i<words.size(); i++){
        char front = words[i][0];
        if(back!=front)
            return sol(i,n);
        else {
            back = words[i][words[i].length()-1];
            string tmp = words[i];
            for(int j=0; j<i; j++)
                if(tmp==words[j])
                    return sol(i,n);
        }
    }
    return {0,0};
}
