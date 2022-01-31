//mentoring 102. 2022.1.28
//pair로 만든 트리의 전위, 중위, 후위 순회

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> edge[26];//<lchild, rchild>

void preOrder(char cur) {//전위순회
	if (cur == '.')return;
	cout << cur;
	preOrder(edge[cur - 'A'].first);
	preOrder(edge[cur - 'A'].second);
}

void inOrder(char cur) {//중위순회
	if (cur == '.')return;
	inOrder(edge[cur - 'A'].first);
	cout << cur;
	inOrder(edge[cur - 'A'].second);
}

void postOrder(char cur) {//후위순회
	if (cur == '.') return;
	postOrder(edge[cur - 'A'].first);
	postOrder(edge[cur - 'A'].second);
	cout << cur;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c, left, right;
		cin >> c >> left >> right;
		edge[c - 'A'] = { left,right };
	}

	preOrder('A');
	cout << '\n';
	inOrder('A');
	cout << '\n';
	postOrder('A');

	return 0;
}
