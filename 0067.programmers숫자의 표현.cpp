//mentoring 67. 2022.1.14

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0, num = 1;
    while (true) {
        int sum = 0;
        for (int i = 1; i <= num; i++)
            sum += i;
        if (sum > n) break;
        if ((n - sum) % num++ == 0)
            answer++;
    }
    return answer;
}
