//mentoring 194. 2022.3.20
//구현

#include <string>
#include <vector>
using namespace std;

int check[4]={0, };
char operation[3]={'*', '+', '-'};
vector<long long> number;
vector<char> op, v;
long long answer = 0;

long long calculate(long long a, long long b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
}

long long sol(){
    vector<char> sol_op=op;
    vector<long long> sol_number=number;
    for(int i=0; i<3; i++){
        char c=v[i];
        int idx=0;
        while(idx<sol_op.size()){
            if(sol_op[idx]==c){
                long long result=calculate(sol_number[idx], sol_number[idx+1], c);
                sol_number[idx]=result;
                sol_number.erase(sol_number.begin()+idx+1);
                sol_op.erase(sol_op.begin()+idx);
                continue;
            }
            idx++;
        }
    }
    return abs(sol_number[0]);
}

void dfs(int cnt){
    if(cnt==3){
        long long result=sol();
        answer=max(answer, result);
        return;
    }

    for(int i=0; i<3; i++)
        if(!check[i]){
            check[i]=1;
            v.push_back(operation[i]);
            dfs(cnt+1);
            v.pop_back();
            check[i]=0;
        }
}

long long solution(string expression) {
    string str="";
    for (int i = 0; i < expression.size(); i++)
        if (!isdigit(expression[i])){
            number.push_back(stoll(str));
            op.push_back(expression[i]);
            str = "";
        }
        else str += expression[i];
    number.push_back(stoll(str));

    dfs(0);

    return answer;
}
