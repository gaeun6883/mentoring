//mentoring 247. 2022.5.30
//dfs

#include <string>
#include <vector>
#include <map>
using namespace std;
 
void dfs(int cur, int cost, vector<int> r, vector<int> &money){
    if (cur == 0) return;
    
    int give = cost / 10;
    if (give ==0){
        money[cur] += cost;
        return;
    }

    money[cur] += (cost-give);
    dfs(r[cur], give, r, money);
}
 
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, int> m;
    vector<int> recommandP(enroll.size() + 1);
    vector<int> money(enroll.size() + 1, 0);

    int num = 1;
    for (int i = 0; i < enroll.size(); i++){
        string s = enroll[i];
        m[s] = num++;
    }
 
    for (int i = 0; i < enroll.size(); i++){
        string child = enroll[i];
        int Child = m[child];
 
        string parent = referral[i];
        if (parent == "-")    
            recommandP[Child] = 0;
        else{
            int Parent = m[parent];
            recommandP[Child] = Parent;
        }
    }
 
    for (int i = 0; i < seller.size(); i++){
        int Seller = m[seller[i]];
        int cost = amount[i] * 100;
 
        dfs(Seller, cost, recommandP, money);
    }
 
    for(int i = 1; i <= enroll.size(); i++)
        answer.push_back(money[i]);
    return answer;
}
