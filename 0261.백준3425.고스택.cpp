//mentoring 261. 2022.7.8
//stack

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

vector <string> comand;
vector <long long> v;
stack <long long> st;

int NUM(long long x);
int POP();
int INV();
int DUP();
int SWP();
int ADD();
int SUB();
int MUL();
int DIV();
int MOD();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        v.clear();
        comand.clear();
        int state = 0;


        while (true) {
            string cmd;
            cin >> cmd;
            if (cmd == "QUIT") return 0;
            if (cmd == "END") break;
            if (cmd == "NUM") {
                long long num;
                cin >> num;
                v.push_back(num);
            }
            comand.push_back(cmd);
        }

        long long n;
        cin >> n;
        while (n--) {
            long long idx = 0, num;
            cin >> num;
            st.push(num);

            for (long long i = 0; i < comand.size(); i++) {
                if (comand[i] == "NUM") state = NUM(v[idx++]);
                else if (comand[i] == "POP") state = POP();
                else if (comand[i] == "INV") state = INV();
                else if (comand[i] == "DUP") state = DUP();
                else if (comand[i] == "SWP") state = SWP();
                else if (comand[i] == "ADD") state = ADD();
                else if (comand[i] == "SUB") state = SUB();
                else if (comand[i] == "MUL") state = MUL();
                else if (comand[i] == "DIV") state = DIV();
                else if (comand[i] == "MOD") state = MOD();

                if (!st.empty() && (llabs(st.top()) > 1000000000))
                    state=1;

                if (state) break;
            }

            if (state || st.size() != 1) cout << "ERROR\n";
            else cout << st.top() << '\n';

            while (!st.empty()) st.pop();
        }
        cout << '\n';
    }
}

int NUM(long long x) {
    st.push(x);
    return 0;
}

int POP() {
    if (st.empty()) return 1;
    st.pop();
    return 0;
}

int INV() {
    if (st.empty()) return 1;
    long long tmp = st.top();
    st.pop();
    st.push(-tmp);
    return 0;
}

int DUP() {
    if (st.empty()) return 1;
    st.push(st.top());
    return 0;
}

int SWP() {
    if (st.size() < 2) return 1;
    long long tmp1 = st.top();
    st.pop();
    long long tmp2 = st.top();
    st.pop();
    st.push(tmp1);
    st.push(tmp2);
    return 0;
}

int ADD() {
    if (st.size() < 2) return 1;
    long long tmp1 = st.top();
    st.pop();
    long long tmp2 = st.top();
    st.pop();
    st.push(tmp1 + tmp2);
    return 0;
}

int SUB() {
    if (st.size() < 2) return 1;
    long long tmp1 = st.top();
    st.pop();
    long long tmp2 = st.top();
    st.pop();
    st.push(tmp2 - tmp1);
    return 0;
}

int MUL() {
    if (st.size() < 2) return 1;
    long long  tmp1 = st.top();
    st.pop();
    long long tmp2 = st.top();
    st.pop();
    st.push(tmp2 * tmp1);
    return 0;
}

int DIV() {
    if (st.size() < 2) return 1;
    long long tmp1 = st.top();
    st.pop();
    long long tmp2 = st.top();
    st.pop();
    if (!tmp1) return 1;
    long long result = llabs(tmp2) / llabs(tmp1);
    if (tmp1 * tmp2 < 0) result *= -1;
    st.push(result);
    return 0;
}

int MOD() {
    if (st.size() < 2) return 1;
    long long tmp1 = st.top();
    st.pop();
    long long tmp2 = st.top();
    st.pop();
    if (!tmp1) return 1;

    long long result = llabs(tmp2) % llabs(tmp1);
    if (tmp2 < 0) result *= -1;
    st.push(result);
    return 0;
}
