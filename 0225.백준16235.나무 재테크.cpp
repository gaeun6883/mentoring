//mentoring 225. 2022.5.7
//구현

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 103
using namespace std;

int n, m, k, a[MAX][MAX], map[MAX][MAX], result = 0;
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector<int> tree[MAX][MAX];

void solution();
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			map[i][j] = 5;
			cin >> a[i][j];
		}
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		tree[a][b].push_back(c);
	}

	for (int i = 0; i < k; i++)
		solution();

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			result += tree[i][j].size();
	cout << result;
	return 0;
}

void solution() {
    for (int i = 1; i <= n; i++){//spring & summer
        for (int j = 1; j <= n; j++){
            if (!tree[i][j].size()) continue;
            int energy = 0;
            vector<int> tmp;
            sort(tree[i][j].begin(), tree[i][j].end());
            for (int k = 0; k < tree[i][j].size(); k++){
                int age = tree[i][j][k];
                if (map[i][j] >= age){
                    map[i][j] -=age;
                    tmp.push_back(age + 1);
                }
                else
                    energy += (age / 2);
            }
            tree[i][j].clear();
            for (int k = 0; k < tmp.size(); k++)
                tree[i][j].push_back(tmp[k]);
            map[i][j] += energy;
        }
    }

    for (int i = 1; i <= n; i++)//fall
        for (int j = 1; j <= n; j++) {
            if (tree[i][j].size() == 0) continue;
            for (int k = 0; k < tree[i][j].size(); k++) {
                int age = tree[i][j][k];
                if (age % 5 == 0)
                    for (int dir = 0; dir < 8; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if (nx >= 1 && ny >= 1 && nx <= n && ny <= n)
                            tree[nx][ny].push_back(1);
                    }
            }
        }

    for (int i = 1; i <= n; i++)//winter
        for (int j = 1; j <= n; j++)
            map[i][j] += a[i][j];
}
