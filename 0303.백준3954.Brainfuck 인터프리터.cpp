//mentoring 303. 2022.8.20
//구현

#include <iostream>
#include <stack>
#include <climits>
#define MAX 100003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int M, C, I;
		string program, input;
		cin >> M >> C >> I;
		cin >> program >> input;

		int idx[MAX], mem[MAX]={};
		stack<int> s;
		for (int i = 0; i < C; i++) {
			if (program[i] == '[') s.push(i);
			if (program[i] == ']') {
				int tmp = s.top();
				idx[i] = tmp;
				idx[tmp] = i;
				s.pop();
			}
		}

		bool state = false;
		int result = INT_MAX, ptr = 0, p_idx = 0, cnt = 0;
		for (int i = 0; i < C; i++) {
			if (program[i] == '-') mem[ptr] = (mem[ptr] + 255) % 256;
			if (program[i] == '+') mem[ptr] = (mem[ptr] + 1) % 256;
			if (program[i] == '<') ptr = (ptr - 1 + M) % M;
			if (program[i] == '>') ptr = (ptr + 1) % M;
			if (program[i] == '[' && mem[ptr]==0) i = idx[i];
			if (program[i] == ']' && mem[ptr]!=0) i = idx[i];
			if (program[i] == ',') mem[ptr] = (p_idx == I ? 255 : (int)input[p_idx++]);

			if (cnt > 50000000) result = min(result, i);
			if (cnt > 100000000) state = true;

			if (++cnt && state) {
				cout << "Loops " << result << " " << idx[result] << "\n";
				break;
			}
		}
		if (!state) cout << "Terminates\n";
	}
	return 0;
}
