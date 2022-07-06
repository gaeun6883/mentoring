//mentoring 258. 2022.7.2
//구현 & dfs

﻿#include <iostream>
using namespace std;

int dice[10], check[35] = { 0, }, h[4], result = 0;
int board[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,21,23,24,25,26,27,20,29,30,25,32,25};
int blue[] = { 0, 22,31,28,0,26 };
int score[] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0,13,16,19,25,30,35,28,27,26,22,24 };

void dfs(int cnt, int sum) {
	if (cnt == 10) {
		if (sum > result)
			result = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int before = h[i];
		int cur = before;
		int move = dice[cnt];

		if (cur%5==0&& blue[cur/5]>0) {
			cur = blue[cur/5];
			move--;
		}

		while (move--)
			cur = board[cur];

		if (cur == 21 || !check[cur]) {
			check[before] = 0;
			check[cur] = 1;
			h[i] = cur;
			dfs(cnt + 1, sum + score[cur]);
			h[i] = before;
			check[before] = 1;
			check[cur] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; i++)
		cin >> dice[i];

	dfs(0, 0);
	cout << sizeof(score)/sizeof(score[0])<<"-"<< sizeof(board)/sizeof(board[0]) << "\n";
	cout << result;
	return 0;
}
