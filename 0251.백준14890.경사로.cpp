//mentoring 251 2022.6.25
//구현

#include <iostream>
#define MAX 103
using namespace std;

int n, l, row_map[MAX][MAX], col_map[MAX][MAX];
bool check(int map[MAX][MAX], int a, int b);
int sol(int idx, int map[MAX][MAX]) {
	int length = 1;
	for (int j = 0; j < n - 1; j++)
		if (map[idx][j] == map[idx][j + 1])
			length++;
		else if (map[idx][j] == map[idx][j + 1] + 1) {
			if (check(map, idx, j + 1)) {
				j += l - 1;
				length = 0;
			}
			else return false;
		}
		else if (map[idx][j] == map[idx][j + 1] - 1) {
			if (length >= l) length = 1;
			else return false;
		}
		else if (abs(map[idx][j] - map[idx][j + 1]) >= 2) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l;
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			cin >> row_map[i][j];
			col_map[j][i] = row_map[i][j];
		}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (sol(i, row_map))
			cnt++;
		if (sol(i, col_map))
			cnt++;
	}
	cout << cnt;
	return 0;
}

bool check(int map[MAX][MAX], int a, int b) {
	int h = map[a][b];
	for (int i = b; i < b+l; i++)
		if (map[a][i] != h)
			return false;
	return true;
}
