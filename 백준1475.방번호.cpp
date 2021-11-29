//mentoring 3. 2021.11.1
//벡터의 사용

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

//기본 배열로 풀이
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int setList[10];
	for (int i = 0; i < 10; i++)
		setList[i] = 0;

	for (int x = 0; x < s.length(); x++) {
		int number = s[x]-'0';
		++setList[number];
	}

	setList[6] = (setList[6] + setList[9]) / 2 + (setList[6] + setList[9]) % 2;
	setList[9] = 0;

	int max = 0;
	for (int y = 0; y < 9; y++) {
		if (max < setList[y])
			max = setList[y];
	}
	printf("%d", max);
	return 0;
}

//벡터로
/*int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	vector<int> setList;
	for (int i = 0; i < 10; i++)
		setList.push_back(0);

	for (int x = 0; x < s.length(); x++) {
		int number = s[x] - '0';
		++setList[number];
	}

	setList[6] = (setList[6] + setList[9]) / 2 + (setList[6] + setList[9]) % 2;
	setList[9] = 0;

	int max = 0;
	for (int y = 0; y < 9; y++) {
		if (max < setList[y])
			max = setList[y];
	}
	cout<<max;
	return 0;
}*/
