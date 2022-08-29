//mentoring 296. 2022.8.13
//세그먼트 트리

#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int n, k;
int arr[MAX], tree[4 * MAX];

int change(int a){
	if(a<0) return -1;
	else if(a>0) return 1;
	else if(a==0) return 0;
}

long long init(int left, int right, int node) {
	if (left == right) return tree[node] = change(arr[left]);
	int mid = (left + right) / 2;
	return tree[node] = init(left, mid, node * 2) * init(mid + 1, right, node * 2 + 1);
}

long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (nodeLeft > right || nodeRight < left) return 1;
	if (nodeLeft >= left && right >= nodeRight) return tree[node];
	int mid = (nodeLeft + nodeRight) / 2;
	return query(left, right, node * 2, nodeLeft, mid) * query(left, right, node * 2 + 1, mid + 1, nodeRight);
}

void update(int idx, long long value, int node, int start, int end) {
	if (idx < start || end < idx) return;
	if (start == end) {
		tree[node] = value;
		return;
	}
	int mid = (start + end) / 2;
	update(idx, value, node * 2, start, mid);
	update(idx, value, node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<char> result;
	while (true) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		init(1, n, 1);
		for (int j = 1; j <= k; j++) {
			char c;
			int a, b;
			cin >> c >> a >> b;
			if (c == 'C') update(a, b, 1, 1, n);
			else {
				int tmp = query(a, b, 1, 1, n);
				if (tmp > 0) //cout << "+";
					result.push_back('+');
				else if (tmp < 0) //cout << "-";
					result.push_back('-');
				else //cout << "0";
					result.push_back('0');
			}
		}
		//result.push_back('/');
		for (int i = 0; i < result.size(); i++)
			cout << result[i];
		result.clear();
		cout << "\n";
	}
	/*for (int i = 0; i < result.size() - 1; i++)
		if (result[i] == '/') cout << "\n";
		else cout << result[i];*/
	return 0;
}
