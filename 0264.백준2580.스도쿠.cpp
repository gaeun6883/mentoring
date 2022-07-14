//mentoring 264.7.11
//dfs

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int map[9][9];
bool state = false;
vector<pair<int, int>> blank;

bool check(int a, int b, int t);
void dfs(int cnt) {
	if (state) return;
	if (cnt == blank.size()) {
		state = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << map[i][j] << " ";
			cout << "\n";
		}
		return;
	}

	int x = blank[cnt].first;
	int y = blank[cnt].second;
	for(int i=1; i<=9; i++)
		if (check(x, y, i)) {
			map[x][y] = i;
			dfs(cnt + 1);
			map[x][y] = 0;
		}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				blank.push_back({ i,j });
		}

	dfs(0);
	return 0;
}

bool check(int a, int b, int t) {
	//1.
	for (int i = 0; i < 9; i++) {
		if (map[a][i] == t) return false;
		else if (map[i][b] == t) return false;
	}

	//2.
	for (int i = (a / 3) * 3; i < (a / 3) * 3 + 3; i++) {
		for (int j = (b / 3) * 3; j < (b / 3) * 3 + 3; j++) {
			if (map[i][j] == t)
				return false;
		}
	}

	return true;
}
