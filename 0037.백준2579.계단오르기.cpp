//mentoring 37. 2021.12.29
//다이나믹 프로그래밍 학습

#include <iostream>
using namespace std;
#define MAX 302

int main() {
	int N;
	cin >> N;
	int stair[MAX];
	for (int i = 0; i < N; i++)
		cin >> stair[i];

	int stair_max[MAX];
	stair_max[0] = stair[0];
	stair_max[1] = stair[0]+stair[1];
	stair_max[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
	for (int i = 3; i < N; i++)
		stair_max[i] = max(stair[i] + stair_max[i - 2], stair[i] + stair[i - 1] + stair_max[i - 3]);
	cout << stair_max[N-1];
}
