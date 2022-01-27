//mentoring 92. 2022.1.25
//n진수

#include <iostream>
#include <string>
using namespace std;

string solution(int n) {
	if (n == 0)
		return "0";

	string result="";
	while (n != 0)
		if (n % -2 == 0){
			result = "0"+result;
			n /= -2;
		}
		else{
			result = "1"+result;
			n = (n - 1) / -2;
		}
	return result;
}

int main() {
	int n;
	cin >> n;
	cout << solution(n);
	return 0;
}
