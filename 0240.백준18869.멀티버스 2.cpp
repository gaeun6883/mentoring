//mentoring 2022.5.23
//이진탐색

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>>v[100];
int n,m;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++){
			int num;
			cin >> num;
			v[i].push_back({ num,j });
		}
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < n - 1; j++)
			if (v[i][j].first == v[i][j + 1].first)
				v[i][j + 1].second = v[i][j].second;
	}

	int result = 0;
	for (int i = 0; i < m- 1; i++){
		for (int j = i + 1; j < m; j++) {
			int l = 0,  r= n;
			bool state = true;
			while (l < r && state){
				int mid = (l + r) / 2;
				if (v[i][mid].second == v[j][mid].second)
					l = mid + 1;
				else
					state = false;
			}

			if (state) result++;
		}
	}

	cout << result;
	return 0;
}
