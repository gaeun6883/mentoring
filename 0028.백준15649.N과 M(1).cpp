//mentoring 28. 2021.12.24
//백트레킹 학습(기본원리)

#include <iostream>
#define MAX 10
using namespace std;

int N, M;
int list[MAX], visited[MAX];

void dfs(int cur) {
   if (cur == M) {
      for (int i = 0; i < M; i++)
         cout << list[i] << " ";
      cout << "\n";
      return;
   }
    for (int j = 1; j <= N; j++) {
        if (!visited[j]) {
            visited[j] = true;
            list[cur] = j;
            dfs(cur + 1);
            visited[j] = false;
        }
    }
}

int main() {
   cin >> N >> M;
   dfs(0);
}
