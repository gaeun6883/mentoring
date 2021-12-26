//mentoring 30. 2021.12.25
//백트레킹 응용

#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

int N, M;
int list[MAX] = { 0, };
int arr[MAX];
bool visited[MAX] = { false, };

void dfs_2(int cur, int n) {
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
            dfs_2(cur + 1, j + 1);
            visited[j] = false;
        }
    }
}
void dfs_3(int cur) {
    if (cur == M) {
        for (int i = 0; i < M; i++)
            cout << list[i] << " ";
        cout << "\n";
        return;
    }
    for (int j = 1; j <= N; j++) {
        visited[j] = true;
        list[cur] = j;
        dfs_3(cur + 1);
        visited[j] = false;
    }
}
void dfs_4(int cur, int n) {
    if (cur == M) {
        for (int i = 0; i < M; i++)
            cout << list[i] << " ";
        cout << "\n";
        return;
    }
    for (int j = n; j <= N; j++) {
            visited[j] = true;
            list[cur] = j;
            dfs_4(cur + 1,j);
            visited[j] = false;
    }
}
void dfs_5(int cur) {
    if (cur == M) {
        for (int i = 0; i < M; i++)
            cout << list[i] << " ";
        cout << "\n";
        return;
    }
    for (int j = 1; j <= N; j++) {
        if (!visited[j]) {
            list[cur] = arr[j-1];
            visited[j] = true;
            dfs_5(cur + 1);
            visited[j] = false;
        }
    }
}
void dfs_6(int cur, int n) {
    if (cur == M) {
        for (int i = 0; i < M; i++)
            cout << list[i] << " ";
        cout << "\n";
        return;
    }
    for (int j = n; j <= N; j++) {
        if (!visited[j]) {
            list[cur] = arr[j - 1];
            visited[j] = true;
            dfs_6(cur + 1, j+1);
            visited[j] = false;
        }
    }
}
void dfs_7(int cur) {
    if (cur == M) {
        for (int i = 0; i < M; i++)
            cout << list[i] << " ";
        cout << "\n";
        return;
    }
    for (int j = 1; j <= N; j++) {
        list[cur] = arr[j - 1];
        visited[j] = true;
        dfs_7(cur + 1);
        visited[j] = false;
    }
}
void dfs_8(int cur, int n) {
    if (cur == M) {
        for (int i = 0; i < M; i++)
            cout << list[i] << " ";
        cout << "\n";
        return;
    }
    for (int j = n; j <= N; j++) {
        list[cur] = arr[j - 1];
        visited[j] = true;
        dfs_8(cur + 1, j);
        visited[j] = false;
    }
}
void dfs_9(int cur) {
    if (cur == M) {
        for (int i = 0; i < M; i++)
            cout << list[i] << " ";
        cout << "\n";
        return;
    }
    int tmp=-1;
    for (int j = 0; j <= N; j++) {
        if (!visited[j] && arr[j] != tmp) {
            list[cur] = arr[j];
            tmp = list[cur];
            visited[j] = true;
            dfs_9(cur + 1);
            visited[j] = false;
        }
    }
}
int main() {
    cin >> N >> M;

    //dfs_2(0,,1);
    //dfs_3(0);
    //dfs_4(0, 1);

    /*for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr+N);*/

    //dfs_5(0);
    //dfs_6(0,1);
    //dfs_7(0);
    //dfs_8(0,1);
    //dfs_9(0);
}
