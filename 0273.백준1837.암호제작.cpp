//mentoring 273. 2022.7.20
//에라토스테네스의 체

#include <iostream>
#include <cstring>
#define MAX 1000003
using namespace std;

string p;
int k, r, prime[MAX];

bool isPrime(int n) {
    int tmp = 0;
    for (int i = 0; i < p.size(); i++)
        tmp = (tmp * 10 + (p[i] - '0')) % n;
    if (tmp == 0) return true;
    return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> p >> k;

    bool state = true;
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i < k; i++) {
        if (prime[i]) continue;
        if (isPrime(i)) {
            state = false;
            r = i;
            break;
        }
        for (long long j = 2 * i; j*j < k; j += i)
            prime[j] = 1;
    }

    if (state) cout << "GOOD";
    else cout << "BAD " << r;
	return 0;
}
