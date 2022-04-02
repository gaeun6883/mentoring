//mentoring 202. 2022.3.28
//bfs 구현

#include <bits/stdc++.h>
using namespace std;
int N;

int mtrx[21][21];
int favorite[1000][4];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
//x,y,빈 칸수,좋아하는 학생칸수
bool comp(const pair<pair<int,int>,pair<int,int>> &p1, const pair<pair<int, int>, pair<int, int>>& p2) {
   if (p1.second.second == p2.second.second) {
      if (p1.second.first == p2.second.first) {
         if (p1.first.first == p2.first.first) {
            return p1.first.second > p2.first.second;
         }
         return p1.first.first > p2.first.first;
      }
      else
         return p1.second.first < p2.second.first;
   }
   return p1.second.second < p2.second.second;

}

int main(void) {
   ios::sync_with_stdio(0);

   cin >> N;
   int Wcnt = N * N;
   while (Wcnt--) {
      int num;
      cin >> num;

      for (int i = 0; i < 4; i++) {
         cin >> favorite[num][i];
      }

      vector<pair<pair<int, int>, pair<int, int>>> v;
      for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
            if (mtrx[i][j] == 0) {

               int emptyCnt = 0;
               int favCnt = 0;

               for (int dir = 0; dir < 4; dir++) {
                  int nx = i + dx[dir];
                  int ny = j + dy[dir];

                  if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                     continue;

                  if (mtrx[nx][ny] == 0) {
                     emptyCnt++;
                  }
                  for (int k = 0; k < 4; k++) {
                     if (mtrx[nx][ny] == favorite[num][k])
                        favCnt++;
                  }
               }

               v.push_back({{i,j}, { emptyCnt,favCnt }   });
            }
         }
      }

      if (!v.empty()) {

         sort(v.begin(), v.end(), comp);
         int x = v.back().first.first;
         int y = v.back().first.second;
         mtrx[x][y] = num;
         v.pop_back();
      }

   }

   int sum = 0;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         int favCnt = 0;
         int num = mtrx[i][j];

         for (int dir = 0; dir < 4; dir++) {
            int nx = i + dx[dir];
            int ny = j + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
               continue;

            for (int k = 0; k < 4; k++) {
               if (mtrx[nx][ny] == favorite[num][k])
                  favCnt++;
            }
         }

         switch (favCnt) {
         case 0:
            sum += 0;
            break;
         case 1:
            sum += 1;
            break;
         case 2:
            sum += 10;
            break;
         case 3:
            sum += 100;
            break;
         case 4:
            sum += 1000;
            break;
         }

      }
   }

   cout << sum << "\n";

   return 0;
}
//초기 코드
/*int n, want[403][5], map[MAX][MAX], visited[MAX][MAX];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };


void solution(int idx);
int statisfaction();
bool cmp(pair<pair<int, int>, pair<int, int>>& a, pair<pair<int, int>, pair<int, int>>& b);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> want[i][0];
		for (int j = 1; j < 5; j++)
			cin >> want[i][j];
	}

	memset(visited, 0, sizeof(visited));
	memset(map, 0, sizeof(map));
	for (int i = 0; i < n * n; i++)
		solution(i);

	cout << statisfaction();
	return 0;
}

void solution(int idx) {
	int st = want[idx][0];
	vector<pair<pair<int, int>, pair<int, int>>> where;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;
			int wantS = 0;
			int empty = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)  continue;
				for (int k = 1; k < 5; k++)
					if (!!visited[nx][ny])
						empty++;
					else if (map[nx][ny]==want[idx][k])
						wantS++;
			}
			where.push_back({ {wantS,empty} ,{i,j} });
		}
	}

	sort(where.begin(), where.end(), cmp);

	int seatR = where[0].second.first;
	int seatC = where[0].second.second;
	map[seatR][seatC] = st;
	visited[seatR][seatC] = 1;
}

int statisfaction() {
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int student = map[i][j];
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if ( nx<1 || nx>n || ny<1 || ny > n) continue;
				for (int num = 0; num < n; num++)
					if (want[student][num] == map[nx][ny])
						cnt++;
			}
			result += pow(10, cnt - 1);
		}
	}
	return result;
}

bool cmp(pair<pair<int, int>, pair<int, int>>& a, pair<pair<int, int>, pair<int, int>>& b) {
	if (a.first.first == b.first.first) {
		if (a.first.second == b.first.second) {
			if (a.second.first == b.second.first)
				return a.second.second < b.second.second;
			return a.second.first < b.second.first;
		}
		return a.first.second > b.first.second;
	}
	return a.first.first > b.first.first;
}*/
