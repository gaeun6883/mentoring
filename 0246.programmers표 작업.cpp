//mentoring 246. 2022.5.29
//구현

#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    stack<int> st;
    vector<int> cur, next;
    for (int i = 0; i < n + 2; i++) {
        cur.push_back(i - 1);
        next.push_back(i + 1);
    }

    k++;
    for (int i = 0; i < cmd.size(); i++) {
         if (cmd[i][0] == 'U')
             for (int j = 0; j < stoi(cmd[i].substr(2)); j++)
                 k = cur[k];

        else if (cmd[i][0] == 'D')
            for (int j = 0; j < stoi(cmd[i].substr(2)); j++)
                k = next[k];

        else if (cmd[i][0] == 'C') {
            st.push(k);
            next[cur[k]] = next[k];
            cur[next[k]] = cur[k];
            if (next[k] == n + 1) k = cur[k];
            else k = next[k];
           }

        else if (cmd[i][0] == 'Z') {
            int n = st.top();
            next[cur[n]] = n;
            cur[next[n]] = n;
            st.pop();
        }
    }

    string answer;
    answer.append(n, 'O');
    while (!st.empty()) {
        answer[st.top() - 1] = 'X';
        st.pop();
    }
    return answer;
}
