//mentoring 168. 2022.3.4
//queue(앞서 푼 유사문제는 vector로 풀이)

#include <iostream>
#include <queue>
#define MAX 1003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, w, l, arr[MAX];
	cin >> n >> w >> l;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int time = 0, weight = 0;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		while (true) {
			if (q.size() == w) {
				weight -= q.front();
				q.pop();
			}
			else if (weight + arr[i] > l) {
				q.push(0);
				time++;
			}
			else {//queue가 비었거나 다리위의 무게초과가 되지 않은 경우
				q.push(arr[i]);
				time++;
				weight += arr[i];
				break;
			}
		}
	}
	int result = time + w;
	cout << result;
	return 0;
}
