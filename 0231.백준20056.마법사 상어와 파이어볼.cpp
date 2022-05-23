//mentoring 231. 2022.5.14
//구현 

#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
typedef struct fireball {
	int r;
	int c;
	int m;
	int s;
	int d;
}fireball;
vector<fireball> v;

void sol();
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	while (m--) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		v.push_back({ a,b,c,d,e });
	}

	while (k--)
		sol();

	int result = 0;
	for (int i = 0; i < v.size(); i++)
		result += v[i].m;
	cout << result;
	return 0;
}

void sol() {
	vector<int> tmp[50][50];
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].m == 0) continue;
		int t = v[i].s % n;
		v[i].r += dx[v[i].d] * t;
		v[i].c += dy[v[i].d] * t;

		if (v[i].r < 0) v[i].r += n;
		if (v[i].r >= n) v[i].r -= n;
		if (v[i].c < 0) v[i].c += n;
		if (v[i].c >= n) v[i].c -= n;

		tmp[v[i].r][v[i].c].push_back(i);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (tmp[i][j].size() < 2) continue;
			int num = tmp[i][j].size();
			int sumM = 0, sumS = 0;
			int state = 0;
			int start=0;
			if (v[tmp[i][j][0]].d % 2 != 0)
				start = 1;

			for (int k = 0; k < num; k++) {
				if (v[tmp[i][j][k]].d % 2 != start) state = 1;
				sumM += v[tmp[i][j][k]].m;
				sumS += v[tmp[i][j][k]].s;
				v[tmp[i][j][k]].m = 0;
			}

			if (sumM / 5 > 0) {
				int nM = sumM / 5;
				int nS = sumS / num;
				if (!state) {
					v.push_back({ i, j, nM, nS, 0 });
					v.push_back({ i, j, nM, nS, 2 });
					v.push_back({ i, j, nM, nS, 4 });
					v.push_back({ i, j, nM, nS, 6 });
				}
				else {
					v.push_back({ i, j, nM, nS, 1 });
					v.push_back({ i, j, nM, nS, 3 });
					v.push_back({ i, j, nM, nS, 5 });
					v.push_back({ i, j, nM, nS, 7 });
				}
			}
		}
}
