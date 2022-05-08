//mentoring 224. 2022.5.6
//dfs & 구현

#include <iostream>
#include <cstring>
using namespace std;

int n, arr[51][10], visited[10], order[10], result = 0;
int score();

void dfs(int cnt) {
	if (cnt == 9) {
		result=max(result, score());
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			order[i] = cnt;
			dfs(cnt + 1);
			visited[i] = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];

	visited[3] = 1;
	order[3] = 0;
	dfs(1);

	cout << result;
	return 0;
}

int score() {
	int score = 0, start = 0;
	bool isNext, base[4];

	for (int i = 0; i < n; i++) {
		int out = 0;
		isNext = true;
		memset(base, false, sizeof(base));
		while (true) {
			for (int j = start; j < 9; j++) {
				int player = arr[i][order[j]];
				if (player == 0) out++;
				else if (player == 1) {
					for (int k = 3; k > 0; k--)
						if(base[k])
							if (k == 3) {
								base[k] = false;
								score++;
							}
							else {
								base[k + 1] = true;
								base[k] = false;
							}
					base[1] = true;
				}
				else if (player == 2) {
					for (int k = 3; k > 0; k--)
						if (base[k])
							if (k == 3 || k == 2) {
								base[k] = false;
								score++;
							}
							else {
								base[k + 2] = true;
								base[k] = false;
							}
					base[2] = true;
				}
				else if (player == 3) {
					for (int k = 3; k > 0; k--)
						if (base[k]) {
							base[k] = false;
							score++;
						}
					base[3] = true;
				}
				else {
					for(int k=3; k>0; k--)
						if (base[k]) {
							base[k] = false;
							score++;
						}
					score++;
				}

				if (out == 3) {
					start = i + 1;
					if (start == 9) start = 0;
					isNext = false;
					break;
				}
			}
			if (!isNext) break;
			start = 0;
		}
	}
	return score;
}
