//mentoring 257.2022.7.1
//bfs

#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 20
using namespace std;

struct horse{
	int x, y, d;
};

int n,k,map[MAX][MAX];
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };
int change[] = { 0, 2, 1, 4, 3 };
vector<horse> h;
vector<int> v[MAX][MAX];

int move(int i);
int sol(){
	int cnt = 1;
	while(cnt<=1000){
		for (int i = 1; i <= k; i++){
			int tmp = move(i);
			if (tmp >= 4)
				return cnt;
		}
		cnt++;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];

	h.push_back({ 0,0,0 });
	for (int i = 1; i <= k; i++){
		int a, b, d;
		cin >> a >> b >> d;
		h.push_back({ a,b,d });
		v[a][b].push_back(i);
	}

	cout << sol();
	return 0;
}

int move(int i){
	int x = h[i].x;
	int y = h[i].y;
	int d = h[i].d;

	int nx = x + dx[d];
	int ny = y + dy[d];

	if (nx <= 0 || ny <= 0 || nx > n || ny > n || map[nx][ny] == 2){//�Ķ�ĭ
		d = h[i].d = change[d];
		nx = x + dx[d];
		ny = y + dy[d];
		if (nx <= 0 || ny <= 0 || nx > n ||ny > n || map[nx][ny] == 2) return 0;
	}

	auto &cur = v[x][y];
	auto &next = v[nx][ny];
	auto s = find(cur.begin(), cur.end(), i);

	if (map[nx][ny] == 1)//����ĭ
		reverse(s, cur.end());

	for (auto idx = s; idx != cur.end(); idx++){
		h[*idx].x = nx;
		h[*idx].y = ny;
		next.push_back(*idx);
	}

	cur.erase(s, cur.end());
	return next.size();
}
