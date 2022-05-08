//mentoring 226. 2022.5.8
//구현

#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#define MAX 102
using namespace std;

int r, c, k, map[MAX][MAX], cnt[MAX];
int solution();
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin>>map[i][j];

	cout << solution();
	return 0;
}

int solution() {
	int time = 0, x = 3, y = 3;
	while (time<=100) {
		if (map[r][c] == k) return time;
		vector<int> v;

		if (x >= y) {
			for (int i = 1; i <= x; i++) {
				vector<pair<int, int>> tmp;
				memset(cnt, 0, sizeof(cnt));
				for (int j = 1; j <= y; j++)
					cnt[map[i][j]]++;
				for (int j = 1; j <= 100; j++)
					if (cnt[j]!=0)
						tmp.push_back({ cnt[j],j });
				sort(tmp.begin(), tmp.end());
				for (int j = 1; j <= y; j++)
					map[i][j] = 0;

				int idx = 1;
				for (int j = 0; j < tmp.size(); j++) {
					map[i][idx++] = tmp[j].second;
					map[i][idx++] = tmp[j].first;
				}
				v.push_back(idx - 1);
			}
			sort(v.begin(), v.end());
			y = v.back();
		}
		else {
			for (int i = 1; i <= y; i++) {
				vector<pair<int, int>> tmp;
				memset(cnt, 0, sizeof(cnt));
				for (int j = 1; j <= x; j++)
					cnt[map[j][i]]++;
				for (int j = 1; j <= 100; j++)
					if (cnt[j]!=0)
						tmp.push_back({ cnt[j],j });
				sort(tmp.begin(), tmp.end());
				for (int j = 1; j <= x; j++)
					map[j][i] = 0;

				int idx = 1;
				for (int j = 0; j < tmp.size(); j++) {
					map[idx++][i] = tmp[j].second;
					map[idx++][i] = tmp[j].first;
				}
				v.push_back(idx - 1);
			}
			sort(v.begin(), v.end());
			x = v.back();
		}

		time++;
	}
	return -1;
}
