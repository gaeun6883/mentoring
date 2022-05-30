//mentoring 243. 2022.5.26
//구현

#include <iostream>
#define MAX 1000003
using namespace std;

int t, n, arr[MAX];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		int profit[MAX];
		profit[n - 1] = n - 1;
		for(int i = n - 2; i >= 0; i--)     //i=day
			if(arr[i] > arr[profit[i + 1]])
				profit[i] = i;
			else profit[i] = profit[i + 1];

		long long result = 0;
		for(int i = 0; i < n; i++)
			if(arr[i] < arr[profit[i]])
				result+= arr[profit[i]] - arr[i];

		cout << result << "\n";
	}
	return 0;
}
